//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_BROADCAST_H
#define EMPATHY_BROADCAST_H

#include <vector>
#include <iostream>
#include "Subscriber.h"
#include "Event.h"
#include <map>

class BroadcastStation {
public:
    //subscribes  a subscriber.
    static void subscribe(Subscriber *base, int id);

    BroadcastStation();

    //emit an event to the whole world
    static void emit(Event e);

protected:
    static BroadcastStation * instance;

private:
    std::map<int,std::vector<Subscriber *>> channels;

    bool existsChannel(int);
    void addChannel(int);
};

#endif //EMPATHY_BROADCAST_H
