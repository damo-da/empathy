//
// Created by damo on 2/4/16.
//

#include "Brain.h"

#include "../you.hpp"

using namespace std;
void Brain::onReceiveEvent(Event &event) {
    Subscriber::onReceiveEvent(event);

    if(event.broadcaster != nullptr && event.broadcaster->getId()==getId()){
        if(event.action==EMPATHY_EVENT_BRAIN_LINE_NUMBER){
            int lineNumber=event.getInt(EMPATHY_EVENT_BRAIN_LINE_NUMBER);
            int caller=event.getInt(EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER);

            runLineNumber(lineNumber,caller);
        }
    }
}

Brain::Brain():
delay(1.0f){

}

void Brain::addLifeEvent(LifeEvent *event) {

    You::getInstance()->addEvent(event);

}

void Brain::run() {
    listenAll();
    activateTimeoutForNextLine(1,getDelay());
}



void Brain::activateTimeoutForNextLine(int lineNumber, GLfloat afterTime) {
    activateTimeoutForNextLine(lineNumber,afterTime,-1);
}

void Brain::activateTimeoutForNextLine(int lineNumber, GLfloat afterTime, int callerLineNumber) {
    Event event=createEvent(EMPATHY_EVENT_BRAIN_LINE_NUMBER);
    event.putInt(EMPATHY_EVENT_BRAIN_LINE_NUMBER,lineNumber);
    event.putInt(EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER,callerLineNumber);

    createTimeOut(afterTime,event);
}

void Brain::addTo(EmpathyBinder *binder) {
    binder->addBrain(this);
}
