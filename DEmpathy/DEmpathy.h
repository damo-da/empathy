/*
	//Your desktop is awesome, and here's the package of Empathy made just for your desktop. Everything that's not cross platform is here!
*/

#ifndef LEMPATHY
#define LEMPATHY

#include "../Empathy/Empathy/Empathy.h"

#include <GLFW/glfw3.h>

#define SC_SIZE_X 700
#define SC_SIZE_Y 700

class DEmpathy : public Empathy{
	/*
	The foundation module for DEmpathy. It manages everything required for the desktop and only the desktop.
	*/

public:
    DEmpathy();

public:
	GLFWwindow * window;

	//Called by the user. Begins the process of the app
	virtual void run();

	//Self explanatory
	virtual void init() override;

	//Initialize the desktop window manager: GLFW3
	void initGlfw();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


private:
    virtual void terminate() override;

    virtual GLfloat getTime() override;

    static DEmpathy * instance;
};


#endif