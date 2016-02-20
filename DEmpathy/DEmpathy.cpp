#include "DEmpathy.h"

#include "DoonLight.h"

using namespace std;
void DEmpathy::run(){
    cout<<"\n\n\n\n\n--------------Program Begin-------------\n\n"<<endl;

    init();

    while(! glfwWindowShouldClose(window)){

        glfwPollEvents();

        loop();

        glfwSwapBuffers(window);
    }
    terminate();
    flush();

    cout<<"\n\n--------------Program End-------------\n\n"<<endl;

}

void DEmpathy::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
//    std::cout<<"key call back received"<<action<<std::endl;

	// When a user presses the escape key, we set the WindowShouldClose property to true,
	// closing the application

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
        glfwSetWindowShouldClose(instance->window, GL_TRUE);
        return;
    }
    std::string myAction="";
    if(action==GLFW_PRESS){
        myAction=EMPATHY_EVENT_INPUT_KEY_PRESS;
    }else if(action==GLFW_RELEASE){
        myAction=EMPATHY_EVENT_INPUT_KEY_RELEASE;
    }else if(action==GLFW_REPEAT){
		myAction=EMPATHY_EVENT_INPUT_KEY_REPEAT;
	}
    if(myAction != ""){
        empathy::radio::Event event=empathy::radio::Event(myAction);
        event.putInt(EMPATHY_EVENT_INPUT_KEY,key);

        empathy::radio::BroadcastStation::emit(event);
    }

}

void DEmpathy::init(){
	instance=this;

	initGlfw();

    setMoonLight(new DoonLight());
    setScreenSize(SC_SIZE_X, SC_SIZE_Y);

    Empathy::init();
}


void DEmpathy::initGlfw() {
//	cout<<"glfwInit"<<endl;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//Create a GLFW window
	window = glfwCreateWindow((GLuint)SC_SIZE_X, (GLuint)SC_SIZE_Y, "Linux Empathy", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	//set key call back
	glfwSetKeyCallback(window, key_callback);
}

DEmpathy *DEmpathy::instance=nullptr;

void DEmpathy::terminate() {
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
}

GLfloat DEmpathy::getTime() {
    return glfwGetTime();
}


DEmpathy::DEmpathy() : Empathy() {

}
