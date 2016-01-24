/*
 * All the life events happen, and You are the one who makes them happen!
 * You handle all the events in life! 
 */

#include "../LifeEvent/life_event.hpp"
#include "../global.hpp"

#include <vector>

class You{
public:
	vector<LifeEvent*> * lifeEvents;

	GLuint shaderProgram;

	You(GLuint &);

	void init();

	long curTime;

	void passTime(long);

	void blit();

	
	void addEvent(LifeEvent *);
	void removeEvent(LifeEvent *);
	void clearEvents();
};