#include "you.hpp"

void You::passTime(GLfloat timeLength){
	curTime += timeLength;

	for(int i=0;i<lifeEvents->size();i++){
		LifeEvent * event=(*lifeEvents)[i];

		// cout <<"Passing time"<<endl;
		event->passTime(timeLength);
		// cout <<"Passed time"<<endl;
	}

	// cout<<"DONE"<<endl;
}
void You::passTime(){
	calcFPS();
	passTime(deltaTime);
}