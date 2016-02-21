//
// Created by damo on 1/25/16.
//

#include "Subscriber.h"
#include "BroadcastStation.h"
#include "../Utils/Uniqueness.h"
#include "TimeBroadcaster.h"
#include "../MoonLight/MoonLight.h"


using namespace std;
void empathy::radio::Subscriber::emit(Event & event) {
    event.broadcaster=this;
    event.putInt(EMPATHY_SUBSCRIBER_ID,getId());

    empathy::radio::BroadcastStation::emit(event);
}


void empathy::radio::Subscriber::listen(std::string id) {
    BroadcastStation::subscribe(this,id);
}

void empathy::radio::Subscriber::onReceiveEvent(Event & event) {

}

empathy::radio::Subscriber::Subscriber() {
    id=Uniqueness::newId();

    subscribers.push_back(this);
}

void empathy::radio::Subscriber::createTimeOut(GLfloat start, int id) {
    Event event=createEvent(EMPATHY_EVENT_TIMEOUT);

    createTimeOut(start,event);
}

void empathy::radio::Subscriber::createRepeatingTimeout(GLfloat start,GLfloat interval, int id) {
    Event event=createEvent(EMPATHY_EVENT_REPEAT_TIMEOUT);
    createRepeatingTimeout(start,interval,event);

}

void empathy::radio::Subscriber::createRepeatingTimeout(GLfloat interval, int id) {
    createRepeatingTimeout(interval,interval,id);
}

void empathy::radio::Subscriber::emit(std::string action) {
    Event event=Event(action);
    emit(event);
}

void empathy::radio::Subscriber::listenAll() {
    BroadcastStation::subscribeAll(this);
}



empathy::radio::Event empathy::radio::Subscriber::createEvent() {
    Event event=createEvent(EMPATHY_EVENT_ACTION_NONE);

    return event;
}

empathy::radio::Event  empathy::radio::Subscriber::createEvent(std::string action) {
    Event event=Event(action);

    event.broadcaster=this;

    event.putInt(EMPATHY_SUBSCRIBER_ID,getId());

    return event;
}

void empathy::radio::Subscriber::createRepeatingTimeout(GLfloat interval, Event &event) {
    createRepeatingTimeout(interval,interval,event);
}

void empathy::radio::Subscriber::createRepeatingTimeout(GLfloat start, GLfloat interval, Event &event) {
    TimeBroadcaster::createRepeatingTimeout(this,event,start,interval);
}

void empathy::radio::Subscriber::createTimeOut(GLfloat interval, Event &event) {
    TimeBroadcaster::createTimeout(this,event,interval);
}

void empathy::radio::Subscriber::playAudio(std::string key) {
    Event e=createEvent(EMPATHY_AUDIO_PLAY);
    e.putString(EMPATHY_AUDIO_PLAY,key);
    emit(e);
}

void empathy::radio::Subscriber::playKeyboardAudio(std::string key) {
    Event e=createEvent(EMPATHY_AUDIO_PLAY_KEYBOARD);
    e.putString(EMPATHY_AUDIO_PLAY_KEYBOARD,key);
    emit(e);
}

std::vector<empathy::radio::Subscriber *> empathy::radio::Subscriber::subscribers=std::vector<empathy::radio::Subscriber*>();