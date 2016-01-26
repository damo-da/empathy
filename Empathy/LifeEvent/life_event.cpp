#include "life_event.hpp"
#include "../RadioStation/TimeBroadcaster.h"
#include "../global.hpp"

using namespace std;
LifeEvent::LifeEvent(){
	id=1;

	totalTime=0.0f;
}
void LifeEvent::passTime(GLfloat delTime){
	if(totalTime==0)
		cout<<"delTime is "<<delTime<<endl;

	// cout<<"passing base time"<<endl;
	totalTime += delTime;
	// cout<<"passed base time"<<endl;
}

GLfloat LifeEvent::getTime(){
	// cout<<"getting time"<<endl;
	return totalTime;
}

void LifeEvent::destroy(){
	// Properly de-allocate all resources once they've outlived their purpose

}

void LifeEvent::init(){

}

void LifeEvent::draw(GLuint shaderProgram){
    std::cout<<"Drawing base"<<std::endl;
}

void LifeEvent::createTimeOut(GLfloat interval, int id) {
    timeouts[id]=interval;

    Event event(EMPATHY_EVENT_WAVE_COMPLETE);
    event.broadcaster=this;

    TimeBroadcaster::createTimeout(*this,event,interval);
}

void LifeEvent::createRepeatingTimeout(GLfloat interval, int id) {
    intervals[id]=interval;
}
