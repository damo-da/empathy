#include "empathy.hpp"


void Empathy::init() {
	cout<<"initing emp"<<endl;

	initGlew();

	initGL();

	initShaders();
	
	initYou();
}
void Empathy::initGlew(){
	cout<<"initing glew"<<endl;

	//initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		
	}
}

void Empathy::initShaders(){
	cout<<"initing shaders"<<endl;

	GLuint fragmentShader=emCreateFragmentShader();
	GLuint vertexShader=emCreateVertexShader();

	shaderProgram=emCreateShaderProgram(fragmentShader,vertexShader);
}

void Empathy::initGL(){
	cout<<"initing glViewport"<<sc_size_x<<","<<sc_size_y<<endl;
	glViewport(0, 0, sc_size_x, sc_size_y);
}

void Empathy::initYou(){
	you=new You(shaderProgram);
	you->init();
}