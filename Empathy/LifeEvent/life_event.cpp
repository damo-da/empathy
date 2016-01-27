#include <iostream>
#include "life_event.hpp"
#include "../RadioStation/TimeBroadcaster.h"
#include "../Uniqueness.h"

using namespace std;
LifeEvent::LifeEvent(){
	id=1;

	totalTime=0.0f;
}
void LifeEvent::passTime(GLfloat delTime){
	totalTime += delTime;
}

GLfloat LifeEvent::getTime(){
	// cout<<"getting time"<<endl;
	return totalTime;
}

void LifeEvent::destroy(){
	// Properly de-allocate all resources once they've outlived their purpose

}

void LifeEvent::init(){
    id=Uniqueness::newId();
}

void LifeEvent::draw(GLuint shaderProgram){
    std::cout<<"Drawing base"<<std::endl;
}

void LifeEvent::createTimeOut(GLfloat start, int id) {
    Event event(EMPATHY_EVENT_TIMEOUT);
    event.broadcaster=this;

    event.putInt(EMPATHY_LIFE_EVENT_ID,id);

    TimeBroadcaster::createTimeout(this,event,start);
}

void LifeEvent::createRepeatingTimeout(GLfloat start,GLfloat interval, int id) {
    Event event(EMPATHY_EVENT_REPEAT_TIMEOUT);
    event.broadcaster=this;

    event.putInt(EMPATHY_LIFE_EVENT_ID,id);

    TimeBroadcaster::createRepeatingTimeout(this,event,start,interval);
}

void LifeEvent::createRepeatingTimeout(GLfloat interval, int id) {
    createRepeatingTimeout(interval,interval,id);
}
