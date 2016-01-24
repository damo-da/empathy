/*
* LifeEvents come as happenings. Together, You process LifeEvents in Reality to find out the meaning behind Empathy.
*/

#ifndef EMPATHY_LIFE_EVENT
#define EMPATHY_LIFE_EVENT

#include "../global.hpp"

#include <vector>

class LifeEvent{
public:
	std::string name;
	
	int id;

	LifeEvent(int,std::string &);

	virtual void draw(GLuint)=0;

	virtual void destroy()=0;

	virtual void init()=0;

	LifeEvent();
private:
	
};

#endif