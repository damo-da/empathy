/*
* LifeEvents come as happenings. Together, You process LifeEvents in Reality to find out the meaning behind Empathy.
*/

#ifndef EMPATHY_LIFE_EVENT
#define EMPATHY_LIFE_EVENT

#include "../global.hpp"
#include "../RadioStation/Subscriber.h"

#include <map>
#include <GL/glew.h>

class LifeEvent : public Subscriber{
public:
	virtual void draw(GLuint);

	virtual void destroy();

	virtual void init();

	GLfloat totalTime;
	virtual void passTime(GLfloat);
	GLfloat getTime();
	
	LifeEvent();

    bool shouldDestroy();
    void setShouldDestroy(bool);
private:
	bool finished;


};

#endif