//
// Created by damo on 1/25/16.
//

#include "Subscriber.h"
#include "BroadcastStation.h"
#include "../Uniqueness.h"
#include "TimeBroadcaster.h"

void Subscriber::emit(Event & event) {
    event.broadcaster=this;
    event.putInt(EMPATHY_SUBSCRIBER_ID,getId());

    BroadcastStation::emit(event);
}


void Subscriber::listen(std::string id) {
    BroadcastStation::subscribe(this,id);
}

void Subscriber::onReceiveEvent(Event & event) {

}

Subscriber::Subscriber() {
    id=Uniqueness::newId();
}

void Subscriber::createTimeOut(GLfloat start, int id) {
    Event event(EMPATHY_EVENT_TIMEOUT);
    event.broadcaster=this;

    event.putInt(EMPATHY_SUBSCRIBER_ID,getId());

    TimeBroadcaster::createTimeout(this,event,start);
}

void Subscriber::createRepeatingTimeout(GLfloat start,GLfloat interval, int id) {
    Event event(EMPATHY_EVENT_REPEAT_TIMEOUT);
    event.broadcaster=this;

    event.putInt(EMPATHY_SUBSCRIBER_ID,getId());

    TimeBroadcaster::createRepeatingTimeout(this,event,start,interval);
}

void Subscriber::createRepeatingTimeout(GLfloat interval, int id) {
    createRepeatingTimeout(interval,interval,id);
}

void Subscriber::emit(std::string action) {
    Event event=Event(action);
    emit(event);
}
