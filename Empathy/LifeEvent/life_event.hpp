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
	int id;
    int getId(){return id;}

    std::map<GLfloat ,int> timeouts;
    std::map<GLfloat ,int> intervals;

	virtual void draw(GLuint)=0;

	virtual void destroy()=0;

	virtual void init()=0;

	GLfloat totalTime;
	virtual void passTime(GLfloat);
	GLfloat getTime();
	
	LifeEvent();

	void createTimeOut(GLfloat interval,int);

    void createRepeatingTimeout(GLfloat,GLfloat,int);
	void createRepeatingTimeout(GLfloat,int);
private:

};

#endif