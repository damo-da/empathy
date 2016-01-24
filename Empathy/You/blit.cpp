#include "you.hpp"

void You::blit(){
	
	// cout<<"blitting you"<<endl;

	for(int i=0;i<lifeEvents->size();i++){
		LifeEvent * event=(*lifeEvents)[i];

		event->draw(shaderProgram);
	}
}