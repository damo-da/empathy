#include "empathy.hpp"
#include "Implements/MoonLightBinder.h"

using namespace std;

Empathy::Empathy(EmpathyBinder *binder,MoonLight * moonLightBinder) {
    this->binder=binder;
    this->moonLight=moonLightBinder;
}


void Empathy::flush(){
	cout<<"Flush done"<<endl;

    binder->terminate();

}

void Empathy::init() {
//	cout<<"initing emp"<<endl;

	initGlew();

	initGL();

	initShaders();

	initYou();

    MoonLightBinder::init(moonLight);

    this->moonLight->init();
}
void Empathy::initGlew(){
//	cout<<"initing glew"<<endl;

	//initialize GLEW
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;

	}
}

void Empathy::initShaders(){
//	cout<<"initing shaders"<<endl;

	GLuint fragmentShader=emCreateFragmentShader();
	GLuint vertexShader=emCreateVertexShader();

	shaderProgram=emCreateShaderProgram(fragmentShader,vertexShader);
}

void Empathy::initGL(){
//	cout<<"initing glViewport"<<sc_size_x<<","<<sc_size_y<<endl;
	glViewport(0, 0, sc_size_x, sc_size_y);
}

void Empathy::initYou(){
	you=new You(shaderProgram);
	you->init();
}


GLuint emCreateFragmentShader() {
//    cout<<"created emCreateFragmentShader"<<endl;

    //read the shaders
    // 1. Retrieve the vertex/fragment source code from filePath
    std::string fragmentCode = "#version 330 core\n"
            "out vec4 color;\n"
            "uniform vec4 vertexColor;\n"

            "void main()\n"
            "{\n"
            "  color = vertexColor;\n"
            "}";


    const GLchar* fShaderCode = fragmentCode.c_str();


    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);


    GLint success;
    GLchar infoLog[512];
    //check if shader compiled successfully
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
        infoLog << std::endl;

        return 2;
    }

    return fragmentShader;
}

GLuint emCreateVertexShader() {
//    cout<<"created emCreateVertexShader"<<endl;
    std::string vertexCode = "#version 330 core\n"
            "layout (location = 0) in vec2 position;\n"
            "void main()\n"
            "{\n"
            "  gl_Position = vec4(position.x, position.y, 0.0, 1.0);\n"
            "}";

    const GLchar* vShaderCode = vertexCode.c_str();

    //create vertexShader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);

    //check if shader compiled successfully
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
        infoLog << std::endl;

        return 1;
    }

    return vertexShader;
}

GLuint emCreateShaderProgram(GLuint fragmentShader , GLuint vertexShader) {
//    cout<<"created emCreateShaderProgram"<<endl;

    //create shader program
    GLuint shaderProgram = glCreateProgram();

    //link shader and program
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void Empathy::setScreenSize(int x,int y){
//    cout<<"Set setScreenSize"<<endl;
    sc_size_x=x;
    sc_size_y=y;
}

void Empathy::begin() {
//    cout << "empathy begin" << endl;



    while (! binder->shouldTerminate()) {
        binder->pollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);

        you->setTime(binder -> getTime());

        you->blit();

        binder->swapBuffers();
    }

    you->clearEvents();

    flush();
}

BroadcastStation Empathy::broadcastStation= BroadcastStation();