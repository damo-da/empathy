/*
	//Your desktop is awesome, and here's the package of Empathy made just for your desktop. Everything that's not cross platform is here!
*/

#ifndef LEMPATHY
#define LEMPATHY

#include "../Empathy/Empathy/Empathy.h"

#include <GLFW/glfw3.h>

#define SC_SIZE_X 700
#define SC_SIZE_Y 700

class DEmpathy : public empathy::Empathy{
	/*
	The foundation module for DEmpathy. It manages everything required for the desktop and only the desktop.
	*/

public:
    DEmpathy();

	//Called by the user. Begins the process of the app
	virtual void run();

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
protected:

	//Self explanatory
	virtual void init() override;

	//Initialize the desktop window manager: GLFW3
	void initGlfw();

    virtual void flush() override;

    virtual GLfloat getTime() override;

private:

    static DEmpathy * instance;

    GLFWwindow * window;
};


#endif