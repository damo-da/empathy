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
    if(isCreating()){
        createTime += delTime;

        onCreate(delTime);
    }else if(isRunning()){
        runTime += delTime;

        onRun(delTime);
    }else if(isFinishing()){
        finishTime += delTime;

        onFinish(delTime);
    }else if(isFinished() && !isDestroyed()){
        onDestroy();
        doneDestroying();
    }else{

    }
}

GLfloat LifeEvent::getTime(){
    return totalTime;
}

void LifeEvent::onDestroy(){
    // Properly de-allocate all resources once they've outlived their purpose
    cout<<"Destroyed event "<<getId()<<endl;
}

void LifeEvent::onInit(){
    finished=false;

    createComplete=false;
    runComplete=false;
    finishComplete=false;
    destroyComplete=false;

    createTime=0.0f;
    runTime=0.0f;
    finishTime=0.0f;
}

void LifeEvent::draw(){
//    std::cout<<"Drawing base"<<std::endl;
}


void LifeEvent::setShouldDestroy(bool state){finished=true;}

void LifeEvent::onCreate(GLfloat delTime) {
    doneCreating();
}

void LifeEvent::onRun(GLfloat delTime) {
    doneRunning();
}

void LifeEvent::onFinish(GLfloat delTime) {
    doneFinishing();
}
