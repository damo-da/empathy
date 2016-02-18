#include "lempathy.hpp"
#include "../Empathy/global.hpp"
#include "LoonLight.h"

using namespace std;
void LEmpathy::run(){
    cout<<"\n\n\n\n\n--------------Program Begin-------------\n\n"<<endl;

    init();

    while(! glfwWindowShouldClose(window)){

        glfwPollEvents();

        empathy->loop();

        glfwSwapBuffers(window);
    }
    terminate();
    empathy->flush();

    cout<<"\n\n--------------Program End-------------\n\n"<<endl;

}

void LEmpathy::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
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
        Event event=Event(myAction);
        event.putInt(EMPATHY_EVENT_INPUT_KEY,key);

        BroadcastStation::emit(event);
    }

}

void LEmpathy::init(){
	instance=this;

	initGlfw();
	initEmpathyInstance();

	empathy->init();
}
void LEmpathy::initEmpathyInstance() {
    empathy->setMoonLight(getMoonLight());
	empathy->setScreenSize(SC_SIZE_X, SC_SIZE_Y);
}

void LEmpathy::initGlfw() {
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

LEmpathy * LEmpathy::instance=nullptr;

void LEmpathy::terminate() {
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
}

GLfloat LEmpathy::getTime() {
    return glfwGetTime();
}


LEmpathy::LEmpathy() : EmpathyBinder() {
    setMoonLight(new LoonLight());
}
