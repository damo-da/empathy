//
// Created by damo on 2/4/16.
//

#include "Brain.h"
#include "../You/you.h"
#include "../Empathy/Empathy.h"

using namespace std;
void empathy::brain::Brain::onReceiveEvent(empathy::radio::Event &event) {
    empathy::radio::Subscriber::onReceiveEvent(event);

    if(event.broadcaster != nullptr && event.broadcaster->getId()==getId()){
        if(event.action==EMPATHY_EVENT_BRAIN_LINE_NUMBER){
            std::string lineID=event.getString(EMPATHY_EVENT_BRAIN_LINE_NUMBER);
            std::string caller=event.getString(EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER);

            runLineNumber(lineID,caller);
        }
    }
}

empathy::brain::Brain::Brain():
delay(1.0f){

}

void empathy::brain::Brain::addLifeEvent(empathy::life_event::LifeEvent *event) {

    You::getInstance()->addEvent(event);

}

void empathy::brain::Brain::run() {
    listenAll();
    activateTimeoutForNextLine("begin",getDelay());
}



void empathy::brain::Brain::activateTimeoutForNextLine(std::string lineID, GLfloat afterTime) {
    activateTimeoutForNextLine(lineID,afterTime,"");
}

void empathy::brain::Brain::activateTimeoutForNextLine(std::string lineID, GLfloat afterTime, std::string callerLineID) {
    empathy::radio::Event event=createEvent(EMPATHY_EVENT_BRAIN_LINE_NUMBER);
    event.putString(EMPATHY_EVENT_BRAIN_LINE_NUMBER,lineID);
    event.putString(EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER,callerLineID);

    createTimeOut(afterTime,event);
}

void empathy::brain::Brain::addTo(Empathy *binder) {
    binder->addBrain(this);
}

void empathy::brain::Brain::terminate() {

}
