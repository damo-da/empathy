//
// Created by damo on 1/25/16.
//

#include <assert.h>
#include "BroadcastStation.h"
#include "../empathy.h"
using namespace std;


void empathy::radio::BroadcastStation::subscribe(empathy::radio::Subscriber *subscriber, std::string id) {
    if(!instance->existsChannel(id)){
        instance->addChannel(id);
    }
    assert(subscriber != nullptr);


    instance->channels[id].push_back(subscriber);
}

void empathy::radio::BroadcastStation::emit(empathy::radio::Event & e) {
    instance->events.push_back(e);
}

bool empathy::radio::BroadcastStation::existsChannel(std::string i) {
    return !(channels.find(i) == channels.end());
}

void empathy::radio::BroadcastStation::addChannel(std::string id) {
    channels[id]=std::vector<Subscriber *>();
}

empathy::radio::BroadcastStation::BroadcastStation():
        vipSubscribers(),
        channels()
{
}
empathy::radio::BroadcastStation * empathy::radio::BroadcastStation::instance= new empathy::radio::BroadcastStation();

void empathy::radio::BroadcastStation::dispatch() {
    for (int i=0;i<instance->events.size();i++){

        Event e=instance->events[i];

        if (e.hasString(EMPATHY_EVENT_SUBSCRIBER_IDENTIFIER)){
            string identifier = e.getString(EMPATHY_EVENT_SUBSCRIBER_IDENTIFIER);

            for (int j=0;j<instance->channels[DEFAULT_DEFAULT_SUBSCRIPTION_CHANNEL].size(); j++){
                Subscriber* subscriber = instance->channels[DEFAULT_DEFAULT_SUBSCRIPTION_CHANNEL][j];
                if (subscriber->getIdentifier() == identifier){
                    subscriber->onReceiveEvent(e);
                }
            }
        }

        std::vector<Subscriber*> subscribers= instance->channels[e.action];
        for(int j=0;j<subscribers.size();j++){
            assert(subscribers[j] != nullptr);

            subscribers[j]->onReceiveEvent(e);
        }

        for(int j=0;j<instance->vipSubscribers.size();j++){
            assert(instance->vipSubscribers[j] != nullptr);

            instance->vipSubscribers[j]->onReceiveEvent(e);
        }

    }
    instance->events.clear();
}

void empathy::radio::BroadcastStation::subscribeAll(Subscriber *subscriber) {
    instance->vipSubscribers.push_back(subscriber);

}
