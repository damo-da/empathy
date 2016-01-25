/*
 * All the life events happen, and You are the one who makes them happen!
 * You handle all the events in life! 
 */

#ifndef EMPATHY_YOU
#define EMPATHY_YOU

 
#include "../LifeEvent/life_event.hpp"
#include "../global.hpp"

#include <vector>

class You{
public:
	vector<LifeEvent*> * lifeEvents;

	GLuint shaderProgram;

	You(GLuint &);

	void init();

	void blit();

	
	void addEvent(LifeEvent *);
	void removeEvent(LifeEvent *);
	void clearEvents();

	long curTime;
	float lastTime,deltaTime;
	int calcFPS();
	void passTime(GLfloat);
	void passTime();
};

#endif