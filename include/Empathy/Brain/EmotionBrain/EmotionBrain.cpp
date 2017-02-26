#include "EmotionBrain.h"

#include <sys/stat.h>
#include "../../RadioStation/TimeBroadcaster.h"
#include "../../Utils/EmotionVector.h"
#include <vector>

using namespace cv;
using namespace std;

void * batman(void * ptr){
    cout<<"Im batman"<<endl;
}

empathy::brain::EmotionBrain::EmotionBrain()
{
    curl_global_init(CURL_GLOBAL_ALL);

    if(instance != NULL){
        cerr<< "Warning: multiple instance of EmotionBrain created";
    }

    instance = this;
}

void empathy::brain::EmotionBrain::terminate() {
    Brain::terminate();

    cout<<"Cleaning up curl" << endl;

    curl_easy_cleanup(curl);

    curl_global_cleanup();
}

void empathy::brain::EmotionBrain::runLineNumber(std::string lineID, std::string callerID, cJSON *override) {

    if (lineID == "begin"){
        cout << "Emotion brain began" << endl;

        createRepeatingTimeout(4.0, 1);
    }
}

void empathy::brain::EmotionBrain::onReceiveEvent(empathy::radio::Event &event) {
    Brain::onReceiveEvent(event);

    if (event.action == EMPATHY_EVENT_REPEAT_TIMEOUT) {

        run_thread();
    }
}

void empathy::brain::EmotionBrain::upload_image(std::string file_name) {
    CURLcode res;

    std::string file_path = root_path + file_name;

    curl = curl_easy_init();

    string api_base = "https://api.projectoxford.ai/emotion/v1.0/recognize";
    string code = "7831aa507b624cc28593e263d7155b12";
    string content_type_header = "Content-Type: application/octet-stream";
    string token_header = "Ocp-Apim-Subscription-Key: "+code;

    //URL
    curl_easy_setopt(curl, CURLOPT_URL, api_base.c_str());

    //Headers
    struct curl_slist *chunk = NULL;
    chunk = curl_slist_append(chunk, content_type_header.c_str());
    chunk = curl_slist_append(chunk, token_header.c_str());
    res = curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);


    //read the image file
    FILE *fd = fopen(file_path.c_str(), "rb");
    struct stat file_info;
    fstat(fileno(fd), &file_info);


    //Body
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_READDATA, fd);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (curl_off_t)file_info.st_size);


    readBuffer.clear();

    //additional options
//    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    /* Perform the request, res will get the return code */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, EmotionBrain::save_curl_response);

    res = curl_easy_perform(curl);

//    cout<<"Request complete"<<endl;
//    cout<<readBuffer<<endl;

    /* Check for errors */
    if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
    else{
        cout<<"Emotion recognition successful"<<endl;

        parse_result();
    }
}

void empathy::brain::EmotionBrain::capture_image(std::string name_to_save_as) {
    cout<< "Capturing image"<<endl;
    VideoCapture cap(0);
    if( !cap.isOpened() ){

        cout<<"CAP not opened"<<endl;

        exit(33);
    }

    Mat frame;
    // This matrix will store the edges of the captured frame
    cap >> frame;

    imwrite(root_path+name_to_save_as, frame);

    cout<< "Image saved"<<endl;
}

void empathy::brain::EmotionBrain::run_thread() {
    pthread_t id;
    pthread_create(&id, NULL, &(this->runActionInThread), NULL);

    thread_ids.push(id);
}

void * empathy::brain::EmotionBrain::runActionInThread(void *n) {
    std::string file_name = "image.jpg";

    capture_image(file_name);
    upload_image(file_name);
    parse_result();
}

size_t empathy::brain::EmotionBrain::save_curl_response(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    readBuffer.append((const char *) contents, realsize);
    return realsize;
}

CURL * empathy::brain::EmotionBrain::curl = 0;
string empathy::brain::EmotionBrain::readBuffer = "";
std::string empathy::brain::EmotionBrain::root_path = "temp/";
empathy::brain::EmotionBrain * empathy::brain::EmotionBrain::instance = 0;

void empathy::brain::EmotionBrain::parse_result() {
    cJSON * root = cJSON_Parse(readBuffer.c_str());

    int num_faces = cJSON_GetArraySize(root);


    if (num_faces == 0){
        cerr << "Face not found!";
        return;
    }else if(num_faces > 1){
        cerr << "Multiple faces found, using the first one";
    }

    cJSON * element_root = cJSON_GetArrayItem(root, 0);

    cJSON * child_scores = cJSON_GetObjectItem(element_root, "scores");


    cout << "Emitting emotion event"<<endl;
    empathy::radio::Event event(EMPATHY_EVENT_EMOTION_COLLECTED);
    event.putJson("scores", child_scores);
    EmotionBrain::instance->emit(event);
}
