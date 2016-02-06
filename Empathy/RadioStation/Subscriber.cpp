//
// Created by damo on 1/25/16.
//

#include "Subscriber.h"
#include "BroadcastStation.h"
#include "../Uniqueness.h"
#include "TimeBroadcaster.h"
#include "../Implements/MoonLight.h"

using namespace std;
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
    Event event=createEvent(EMPATHY_EVENT_TIMEOUT);

    createTimeOut(start,event);
}

void Subscriber::createRepeatingTimeout(GLfloat start,GLfloat interval, int id) {
    Event event=createEvent(EMPATHY_EVENT_REPEAT_TIMEOUT);
    createRepeatingTimeout(start,interval,event);

}

void Subscriber::createRepeatingTimeout(GLfloat interval, int id) {
    createRepeatingTimeout(interval,interval,id);
}

void Subscriber::emit(std::string action) {
    Event event=Event(action);
    emit(event);
}

void Subscriber::listenAll() {
    BroadcastStation::subscribeAll(this);
}



Event Subscriber::createEvent() {
    Event event=createEvent(EMPATHY_EVENT_ACTION_NONE);

    return event;
}

Event  Subscriber::createEvent(std::string action) {
    Event event=Event(action);

    event.broadcaster=this;

    event.putInt(EMPATHY_SUBSCRIBER_ID,getId());

    return event;
}

void Subscriber::createRepeatingTimeout(GLfloat interval, Event &event) {
    createRepeatingTimeout(interval,interval,event);
}

void Subscriber::createRepeatingTimeout(GLfloat start, GLfloat interval, Event &event) {
    TimeBroadcaster::createRepeatingTimeout(this,event,start,interval);
}

void Subscriber::createTimeOut(GLfloat interval, Event &event) {
    TimeBroadcaster::createTimeout(this,event,interval);
}

void Subscriber::playAudio(std::string key) {
    Event e=createEvent(EMPATHY_AUDIO_PLAY);
    e.putString(EMPATHY_AUDIO_PLAY,key);
    emit(e);
}

void Subscriber::playKeyboardAudio(std::string key) {
    Event e=createEvent(EMPATHY_AUDIO_PLAY_KEYBOARD);
    e.putString(EMPATHY_AUDIO_PLAY_KEYBOARD,key);
    emit(e);
}
