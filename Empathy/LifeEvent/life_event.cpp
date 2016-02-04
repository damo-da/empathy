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


void LifeEvent::onInit(){
    createComplete=false;
    runComplete=false;
    finishComplete=false;
    destroyComplete=false;
    depth=0.0f;

    createTime=0.0f;
    runTime=0.0f;
    finishTime=0.0f;
}

void LifeEvent::onCreate(GLfloat delTime) {
    doneCreating();
}

void LifeEvent::onRun(GLfloat delTime) {
    doneRunning();
}

void LifeEvent::onFinish(GLfloat delTime) {
    doneFinishing();
}

GLfloat LifeEvent::getTotalTime() {
    return totalTime;
}

void LifeEvent::init() {
    if(! initComplete){
        onInit();
    }
    initComplete=true;
}
