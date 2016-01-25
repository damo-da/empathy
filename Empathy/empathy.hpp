#ifndef EMPATHY
#define EMPATHY

#include "global.hpp"

#include "You/you.hpp"

#include "LifeEvent/life_event.hpp"
#include "Implements/EmpathyBinder.h"
#include "RadioStation/BroadcastStation.h"

class Empathy{
public:
    EmpathyBinder * binder;

	//init the cross-platform system ready.
	void init();

	//The constructor
	Empathy(EmpathyBinder * binder);

	//The window is created. Begin serving empathy
	void begin();
	

	void setScreenSize(int,int);

	//The shader program used to render the vertices
	GLuint shaderProgram;

	void flush();

	You * you;

    static BroadcastStation broadcastStation;
private:
	//Screen Size
	uint sc_size_x,sc_size_y;

	void initGlew();
	void initShaders();
	void initGL();
	void initYou();
};

GLuint emCreateShaderProgram(GLuint ,GLuint);
GLuint emCreateFragmentShader();
GLuint emCreateVertexShader();

#endif