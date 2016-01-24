#include "you.hpp"

void You::addEvent(LifeEvent * e){
	lifeEvents->push_back(e);
}
void You::removeEvent(LifeEvent * e){
	cout<<"event not removed for NOW!"<<endl;

	e->destroy();
}

void You::clearEvents(){
	for(int i=0;i<lifeEvents->size();i++){
		LifeEvent * event=(*lifeEvents)[i];
		removeEvent(event);
	}
}