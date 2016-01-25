//
// Created by damo on 1/25/16.
//

#include "Subscriber.h"
#include "BroadcastStation.h"

void Subscriber::emit(Event event) {
    BroadcastStation::emit(event);
}

void Subscriber::listen(int id) {
    BroadcastStation::subscribe(this,id);
}
