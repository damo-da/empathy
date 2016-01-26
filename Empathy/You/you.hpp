/*
 * All the life events happen, and You are the one who makes them happen!
 * You handle all the events in life! 
 */

#ifndef EMPATHY_YOU
#define EMPATHY_YOU

 
#include "../LifeEvent/life_event.hpp"
#include "../global.hpp"

#include <vector>

class You: public Subscriber{
public:
	std::vector<LifeEvent*> * lifeEvents;

	GLuint shaderProgram;

	You(GLuint &);

	void init();

	void blit();

	void addEvent(LifeEvent *);
	void removeEvent(LifeEvent *);
	void clearEvents();

	long curTime;
	float lastTime,deltaTime;
	int calcFPS(GLfloat curTime);
	void passTime(GLfloat);
	void setTime(GLfloat);


    virtual void onReceiveEvent(Event event) override;
};

#endif