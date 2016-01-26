//
// Created by damo on 1/25/16.
//

#include "BroadcastStation.h"

void BroadcastStation::subscribe(Subscriber *subscriber, std::string id) {
    if(!instance->existsChannel(id)){
        instance->addChannel(id);
    }

    instance->channels[id].push_back(subscriber);
}

void BroadcastStation::emit(Event * e) {
    if(! instance->existsChannel(e->action))return;

    std::vector<Subscriber*> subscribers= instance->channels[e->action];

    for(int i=0;i<subscribers.size();i++){
        subscribers[i]->onReceiveEvent(e);
    }
}

bool BroadcastStation::existsChannel(std::string i) {
    return !(channels.find(i) == channels.end());
}

void BroadcastStation::addChannel(std::string id) {
    channels[id]=std::vector<Subscriber *>();
}

BroadcastStation::BroadcastStation() {
    instance=this;
}
BroadcastStation * BroadcastStation::instance= nullptr;