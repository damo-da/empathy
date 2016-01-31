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
    return totalTime;
}

void LifeEvent::destroy(){
    // Properly de-allocate all resources once they've outlived their purpose
    cout<<"Destroyed event "<<getId()<<endl;
}

void LifeEvent::init(){
    finished=false;
}

void LifeEvent::draw(){
//    std::cout<<"Drawing base"<<std::endl;
}

bool LifeEvent::shouldDestroy() {
    return finished;

}


void LifeEvent::setShouldDestroy(bool state){finished=true;}