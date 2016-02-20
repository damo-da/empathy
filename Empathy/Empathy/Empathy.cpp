#include "Empathy.h"

#include "../Shader/include.h"
#include "../MoonLight/include.h"
#include "../You/include.h"
using namespace std;

empathy::Empathy::Empathy():
moonLight(nullptr)
{

}


void empathy::Empathy::flush(){
    cout<<"Flush done"<<endl;

    moonLight->terminate();
    you->terminate();
}

void empathy::Empathy::init() {
//	cout<<"initing emp"<<endl;

    initGlew();

    initGL();

    initShaders();

    initYou();


    std::vector<empathy::brain::Brain *> brains=this->getBrains();
    for(int i=0;i<brains.size();i++){
        you->addBrain(brains[i]);
    }
    this->moonLight->init();
}
void empathy::Empathy::initGlew(){
//	cout<<"initing glew"<<endl;

    //initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;

    }
}

void empathy::Empathy::initShaders(){
    empathy::shader::DefaultShader::init();
}

void empathy::Empathy::initGL(){
//	cout<<"initing glViewport"<<sc_size_x<<","<<sc_size_y<<endl;
    glViewport(0, 0, sc_size_x, sc_size_y);
}

void empathy::Empathy::initYou(){
    you=new empathy::You();
    you->init();
}


void empathy::Empathy::setScreenSize(int x,int y){
//    cout<<"Set setScreenSize"<<endl;
    sc_size_x=x;
    sc_size_y=y;
}


empathy::radio::BroadcastStation empathy::Empathy::broadcastStation= empathy::radio::BroadcastStation();

void empathy::Empathy::loop() {

    empathy::radio::BroadcastStation::dispatch();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT );

    you->setTime(getTime());

    you->blit();

}

void empathy::Empathy::addBrain(empathy::brain::Brain *brain) {
    brains.push_back(brain);
}
