#include "Subscriber.h"
#include "BroadcastStation.h"
#include "../Utils/UniqueObject.h"
#include "../empathy.h"
#include "TimeBroadcaster.h"
#include "../MoonLight/MoonLight.h"
#include "../Utils/string_utils.h"


using namespace std;

empathy::radio::Subscriber::Action convertToAction(cJSON* data);

void empathy::radio::Subscriber::emit(Event & event) {
    event.broadcaster=this;
    event.putInt(EMPATHY_SUBSCRIBER_ID,getId());

    empathy::radio::BroadcastStation::emit(event);
}


void empathy::radio::Subscriber::listen(std::string id) {
    BroadcastStation::subscribe(this,id);
}

empathy::radio::Subscriber::Subscriber():
        UniqueObject(),
        actions()
{
    setIdentifier(int_to_str(getId()));

    empathy::radio::BroadcastStation::subscribe(this, DEFAULT_DEFAULT_SUBSCRIPTION_CHANNEL);
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

void empathy::radio::Subscriber::dispatchEventToActions(string event_name, Event origEvent) {
    if(Subscriber::actions.size() == 0)return;

    for (int i=0; i<Subscriber::actions.size(); i++){
        Action action = Subscriber::actions[i];

        if (action.on == event_name){
            Event e(origEvent);
            e.action = action.action;

            emitToIdentifier(e, action.id);
        }
    }
}

void empathy::radio::Subscriber::decodeJson(std::string key, cJSON *value) {
    if (key=="$id"){
        setIdentifier(value->valuestring);
    }else if(key=="actions"){
        Subscriber::actions.clear();
        if(value->type==cJSON_Array){
            cJSON * child = value->child;

            while(child){
                Subscriber::actions.push_back(convertToAction(child));
                child = child->next;
            }
        }else {
            Subscriber::actions.push_back(convertToAction(value));
        }

    }
}

std::string empathy::radio::Subscriber::getIdentifier() {
    return Subscriber::identifier;
}

void empathy::radio::Subscriber::setIdentifier(std::string newId) {
    Subscriber::identifier = newId;

}

void empathy::radio::Subscriber::emitToIdentifier(empathy::radio::Event e, std::string identifier) {
    e.putString(EMPATHY_EVENT_SUBSCRIBER_IDENTIFIER, identifier);
    emit(e);
}

void empathy::radio::Subscriber::dispatchEventToActions(std::string event_action) {
    return dispatchEventToActions(event_action, Event(event_action));

}

void empathy::radio::Subscriber::onReceiveEvent(empathy::radio::Event &) {

}


empathy::radio::Subscriber::Action convertToAction(cJSON* data){
    std::string trigger = cJSON_GetObjectItem(data, "on")->valuestring;
    std::string action = cJSON_GetObjectItem(data, "action")->valuestring;
    std::string applyTo = cJSON_GetObjectItem(data, "applyTo")->valuestring;

    return empathy::radio::Subscriber::Action::create(trigger,action,applyTo);
}

