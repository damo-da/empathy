#include "lempathy.hpp"

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