#include "life_event.hpp"

LifeEvent::LifeEvent(int i,std::string &n){
	id=i;
	name=n;


	// cout<<"double constr"<<endl;

	totalTime=0.0f;


}

LifeEvent::LifeEvent(){
	id=5;
	name="LifeEvent";

	// cout<<"none constr"<<endl;
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