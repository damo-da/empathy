/*
* LifeEvents come as happenings. Together, You process LifeEvents in Reality to find out the meaning behind Empathy.
*/

#ifndef EMPATHY_LIFE_EVENT
#define EMPATHY_LIFE_EVENT

#include "../global.hpp"
#include "../RadioStation/Subscriber.h"

#include <vector>

class LifeEvent : public Subscriber{
public:
	std::string name;
	
	int id;

	LifeEvent(int,std::string &);

	virtual void draw(GLuint)=0;

	virtual void destroy()=0;

	virtual void init()=0;

	GLfloat totalTime;
	virtual void passTime(GLfloat);
	GLfloat getTime();
	
	LifeEvent();

	int getId(){return id;}
private:
	
};

#endif