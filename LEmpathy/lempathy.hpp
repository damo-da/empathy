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
	//The instance for the Empathy app
	Empathy * empathy;

	GLFWwindow * window;

	//Called by the user. Begins the process of the app
	void run();

	virtual void preLoop() override;

	virtual void postLoop() override;

//Self explanatory
	void init();

	//Initialize the desktop window manager: GLFW3
	void initGlfw();

	//Creates an instance of the empathy app on this LEmpathy instance.
	void initEmpathyInstance();

	//Called to begin the app. Create a window, start progressing empathy, and everything else
	void begin();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


private:
    virtual bool shouldTerminate() override;

    virtual void terminate() override;

    virtual GLfloat getTime() override;

    static LEmpathy * instance;
};


#endif