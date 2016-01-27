#include <iostream>
#include "life_event.hpp"
#include "../RadioStation/TimeBroadcaster.h"
#include "../Uniqueness.h"

using namespace std;
LifeEvent::LifeEvent(){
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

}

void LifeEvent::draw(GLuint shaderProgram){
    std::cout<<"Drawing base"<<std::endl;
}

