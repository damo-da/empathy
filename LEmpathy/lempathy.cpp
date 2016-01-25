#include "lempathy.hpp"

void LEmpathy::run(){
	
	cout<<"\n\n\n\n\n--------------Program Begin-------------\n\n"<<endl;
	
	init();

	begin();

	cout<<"\n\n--------------Program End-------------\n\n"<<endl;
}

void LEmpathy::begin(){
	cout<<"lempathy begin"<<endl;

	empathy->begin();

	cout << "Finished everything" << endl;
}

void LEmpathy::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	cout<<"key call back received"<<endl;

	//LEmpathy is in the variable `instance`

	// When a user presses the escape key, we set the WindowShouldClose property to true,
	// closing the application

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(instance->window, GL_TRUE);

}


void LEmpathy::init(){
	cout<<"init lempathy"<<endl;
	instance=this;

	initGlfw();
	initEmpathyInstance();

	empathy->init();
}
void LEmpathy::initEmpathyInstance() {
	cout<<"Create empathy instance"<<endl;
	cout<<"passed "<<window<<endl;
	empathy = new Empathy(window);
	empathy->setScreenSize(SC_SIZE_X, SC_SIZE_Y);
}

void LEmpathy::initGlfw() {
	cout<<"glfwInit"<<endl;
	cout<<"Version is "<<glfwInit()<<endl;



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
