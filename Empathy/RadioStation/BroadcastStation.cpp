//
// Created by damo on 1/25/16.
//

#include <assert.h>
#include "BroadcastStation.h"
#include "../You/you.hpp"

using namespace std;


void BroadcastStation::subscribe(Subscriber *subscriber, std::string id) {
    if(!instance->existsChannel(id)){
        instance->addChannel(id);
    }

    instance->channels[id].push_back(subscriber);
}

void BroadcastStation::emit(Event & e) {
    instance->events.push_back(e);
}

bool BroadcastStation::existsChannel(std::string i) {
    return !(channels.find(i) == channels.end());
}

void BroadcastStation::addChannel(std::string id) {
    channels[id]=std::vector<Subscriber *>();
}

BroadcastStation::BroadcastStation():
        vipSubscribers(),
        channels()
{
    instance=this;
}
BroadcastStation * BroadcastStation::instance= nullptr;

void BroadcastStation::dispatch() {
    for (int i=0;i<instance->events.size();i++){


        Event e=instance->events[i];

        std::vector<Subscriber*> subscribers= instance->channels[e.action];
        for(int j=0;j<subscribers.size();j++){
            assert(subscribers[i] != nullptr);

            subscribers[j]->onReceiveEvent(e);
        }

        for(int j=0;j<instance->vipSubscribers.size();j++){
            assert(instance->vipSubscribers[j] != nullptr);

            instance->vipSubscribers[j]->onReceiveEvent(e);
        }

    }
    instance->events.clear();
}

void BroadcastStation::subscribeAll(Subscriber *subscriber) {
    cout<<subscriber->getId()<<" is listening all"<<endl;
    instance->vipSubscribers.push_back(subscriber);

}
