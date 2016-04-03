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

    cout<<"KEY callback"<<endl;
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

    empathy::Empathy::init();
}


void DEmpathy::initGlfw() {
//	cout<<"glfwInit"<<endl;

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    int count;
    GLFWmonitor** monitors=glfwGetMonitors(&count);

	//Create a GLFW window
	window = glfwCreateWindow((GLuint)SC_SIZE_X, (GLuint)SC_SIZE_Y, "Linux Empathy",
                              FULL_SCREEN?glfwGetPrimaryMonitor(): nullptr,
                              nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);

	//set event receiver call backs.
	glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window,mouse_input_callback);
    glfwSetCursorPosCallback(window,mouse_position_callback);
}

DEmpathy *DEmpathy::instance=nullptr;

void DEmpathy::flush() {
    empathy::Empathy::flush();

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
}

GLfloat DEmpathy::getTime() {
    return glfwGetTime();
}


DEmpathy::DEmpathy() : Empathy() {

}

void DEmpathy::mouse_input_callback(GLFWwindow *window, int button, int action, int mods) {
    if(action==GLFW_PRESS){
        empathy::radio::Event event(EMPATHY_EVENT_ACTION_NONE);

        if(button==GLFW_MOUSE_BUTTON_LEFT ){
            event=empathy::radio::Event(EMPATHY_EVENT_INPUT_MOUSE_LEFT_KEY_PRESS);
        }else if(button==GLFW_MOUSE_BUTTON_RIGHT){
            event=empathy::radio::Event(EMPATHY_EVENT_INPUT_MOUSE_RIGHT_KEY_PRESS);
        }

        event.putDouble(EMPATHY_MOUSE_XPOS,instance->mouseX);
        event.putDouble(EMPATHY_MOUSE_YPOS,SC_SIZE_Y-instance->mouseY);


        empathy::radio::BroadcastStation::emit(event);
    }
}

void DEmpathy::mouse_position_callback(GLFWwindow *window, double xpos, double ypos) {
    instance->mouseX=xpos;
    instance->mouseY=ypos;
}
