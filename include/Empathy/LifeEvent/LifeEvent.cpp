#include <iostream>
#include "LifeEvent.h"
#include <assert.h>
#include "../You/you.h"

using namespace std;

empathy::life_event::LifeEvent::LifeEvent() :
        Subscriber(),
        initComplete(false),
        runComplete(false),
        createComplete(false),
        finishComplete(false),
        destroyComplete(false),
        createTime(0.0),
        finishTime(0.0),
        runTime(0.0),
        totalTime(0.0),
        depth(0.0),
        transitions()
{


}
void empathy::life_event::LifeEvent::passTime(GLfloat delTime){
    totalTime += delTime;

    performTransitions();

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

    dispatchEventToActions(EMPATHY_LIFE_EVENT_INIT_COMPLETE);
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

GLfloat empathy::life_event::LifeEvent::getTotalTime() const {
    return totalTime;
}

void empathy::life_event::LifeEvent::init() {
    if(! initComplete){
        onInit();
    }
    initComplete=true;
}

void empathy::life_event::LifeEvent::doneCreating() {
    if(!isCreating())return;

    createComplete=true;
    dispatchEventToActions(EMPATHY_LIFE_EVENT_CREATE_COMPLETE);
    emit(EMPATHY_LIFE_EVENT_CREATE_COMPLETE);
}

void empathy::life_event::LifeEvent::doneRunning() {
    if(!isRunning())return;

    runComplete=true;
    dispatchEventToActions(EMPATHY_LIFE_EVENT_RUN_COMPLETE);
    emit(EMPATHY_LIFE_EVENT_RUN_COMPLETE);
}

void empathy::life_event::LifeEvent::doneFinishing() {
    if(!isFinishing())return;

    finishComplete=true;
    dispatchEventToActions(EMPATHY_LIFE_EVENT_FINISH_COMPLETE);
    emit(EMPATHY_LIFE_EVENT_FINISH_COMPLETE);
}

void empathy::life_event::LifeEvent::onDestroy() {
    if(isDestroyed())return;
    if(!isFinished())return;;

    dispatchEventToActions(EMPATHY_LIFE_EVENT_DESTROYED);
}

void empathy::life_event::LifeEvent::decodeJson(std::string key, cJSON *value) {
    Subscriber::decodeJson(key, value);

    if(key=="transition"){
        std::vector<cJSON *> jsonTransitions;

        if(value->type==cJSON_Object){
            jsonTransitions.push_back(value);
        }else if(value->type==cJSON_Array){
            cJSON * child=value->child;
            while(child){
                jsonTransitions.push_back(child);
                child=child->next;
            }
        }

        for(int i=0;i<jsonTransitions.size();i++){
            cJSON * transition=jsonTransitions[i];

            ValueTransition valueTransition;
            valueTransition.duration=cJSON_GetObjectItem(transition,"duration")->valuedouble;
            valueTransition.from=cJSON_GetObjectItem(transition,"from")->valuedouble;
            valueTransition.to=cJSON_GetObjectItem(transition,"to")->valuedouble;
            valueTransition.key=cJSON_GetObjectItem(transition,"key")->valuestring;
            transitions.push_back(valueTransition);
        }
    }
}

void empathy::life_event::LifeEvent::performTransitions() {
    for(int i=0;i<transitions.size();i++){

        ValueTransition valueTransition=transitions[i];

        //if the transition has expired
        if(getTotalTime() > valueTransition.duration){
            transitions.erase(transitions.begin()+i);
            i--;
            continue;
        }

        GLdouble output=valueTransition.getValue(this);

        cJSON* value=cJSON_CreateNumber(output);

        decodeJson(valueTransition.key,value);
    }
}

void empathy::life_event::LifeEvent::onReceiveEvent(empathy::radio::Event &event) {
    empathy::radio::Subscriber::onReceiveEvent(event);

    if( event.action == EMPATHY_LIFE_EVENT_CREATE ){
        onInit();
    }else if(event.action == EMPATHY_LIFE_EVENT_RUN){
        onInit();
        doneCreating();
    }else if(event.action == EMPATHY_LIFE_EVENT_FINISH){
        doneCreating();
        doneRunning();
    }else if(event.action == EMPATHY_LIFE_EVENT_DESTROY){
        doneCreating();
        doneRunning();
        doneFinishing();
    }
}



