//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_STATIONBASE_H
#define EMPATHY_STATIONBASE_H


#include "Event.h"

//The class to be overridden to emit/receive broadcasts
class Subscriber {
public:
    virtual void onReceiveEvent(Event event);

    void emit(Event);

    void listen(std::string id);
};


#endif //EMPATHY_STATIONBASE_H
