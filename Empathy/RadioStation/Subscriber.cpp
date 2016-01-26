//
// Created by damo on 1/25/16.
//

#include "Subscriber.h"
#include "BroadcastStation.h"

void Subscriber::emit(Event event) {
    event.broadcaster=this;

    BroadcastStation::emit(event);
}

void Subscriber::listen(std::string id) {
    BroadcastStation::subscribe(this,id);
}

void Subscriber::onReceiveEvent(Event event) {

}
