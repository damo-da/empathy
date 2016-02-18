/*
	//Your desktop is awesome, and here's the package of Empathy made just for your desktop. Everything that's not cross platform is here!
*/

#ifndef LEMPATHY
#define LEMPATHY

#include "../Empathy/empathy.hpp"
#include "../Empathy/Implements/EmpathyBinder.h"
#include <GLFW/glfw3.h>

#define SC_SIZE_X 700
#define SC_SIZE_Y 700

class LEmpathy:public EmpathyBinder{
	/*
	The foundation module for LEmpathy. It manages everything required for the desktop and only the desktop.
	*/

public:
    LEmpathy();

public:
	GLFWwindow * window;

	//Called by the user. Begins the process of the app
	virtual void run();

	//Self explanatory
	virtual void init() override;

	//Initialize the desktop window manager: GLFW3
	void initGlfw();

	//Creates an instance of the empathy app on this LEmpathy instance.
	void initEmpathyInstance();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


private:
    virtual void terminate() override;

    virtual GLfloat getTime() override;

    static LEmpathy * instance;
};


#endif