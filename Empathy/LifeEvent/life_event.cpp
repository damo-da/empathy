#include "life_event.hpp"

LifeEvent::LifeEvent(int i,std::string &n){
	id=i;
	name=n;
}

LifeEvent::LifeEvent(){
	id=5;
	name="LifeEvent";
}