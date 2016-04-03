#include <iostream>
#include "LifeEvent.h"

using namespace std;
empathy::life_event::LifeEvent::LifeEvent(): Subscriber(){
    totalTime=0.0f;

}
void empathy::life_event::LifeEvent::passTime(GLfloat delTime){
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


void empathy::life_event::LifeEvent::onInit(){
    createComplete=false;
    runComplete=false;
    finishComplete=false;
    destroyComplete=false;
    depth=0.0f;

    createTime=0.0f;
    runTime=0.0f;
    finishTime=0.0f;
}

void empathy::life_event::LifeEvent::onCreate(GLfloat delTime) {
    doneCreating();
}

void empathy::life_event::LifeEvent::onRun(GLfloat delTime) {
    doneRunning();
}

void empathy::life_event::LifeEvent::onFinish(GLfloat delTime) {
    doneFinishing();
}

GLfloat empathy::life_event::LifeEvent::getTotalTime() {
    return totalTime;
}

void empathy::life_event::LifeEvent::init() {
    if(! initComplete){
        onInit();
    }
    initComplete=true;
}

void empathy::life_event::LifeEvent::doneCreating() {
    createComplete=true;
    emit(EMPATHY_LIFE_EVENT_CREATE_COMPLETE);
}

void empathy::life_event::LifeEvent::doneRunning() {
    runComplete=true;
    emit(EMPATHY_LIFE_EVENT_RUN_COMPLETE);
}

void empathy::life_event::LifeEvent::doneFinishing() {
    finishComplete=true;
    emit(EMPATHY_LIFE_EVENT_FINISH_COMPLETE);
}

void empathy::life_event::LifeEvent::onDestroy() {
//    cout<<"deleted event "<<getId()<<endl;
}

void empathy::life_event::LifeEvent::decodeJson(std::string key, cJSON *value) {

}
