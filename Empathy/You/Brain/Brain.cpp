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
            std::string lineID=event.getString(EMPATHY_EVENT_BRAIN_LINE_NUMBER);
            std::string caller=event.getString(EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER);

            runLineNumber(lineID,caller);
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
    activateTimeoutForNextLine("begin",getDelay());
}



void Brain::activateTimeoutForNextLine(std::string lineID, GLfloat afterTime) {
    activateTimeoutForNextLine(lineID,afterTime,"");
}

void Brain::activateTimeoutForNextLine(std::string lineID, GLfloat afterTime, std::string callerLineID) {
    Event event=createEvent(EMPATHY_EVENT_BRAIN_LINE_NUMBER);
    event.putString(EMPATHY_EVENT_BRAIN_LINE_NUMBER,lineID);
    event.putString(EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER,callerLineID);

    createTimeOut(afterTime,event);
}

void Brain::addTo(EmpathyBinder *binder) {
    binder->addBrain(this);
}

void Brain::terminate() {

}
