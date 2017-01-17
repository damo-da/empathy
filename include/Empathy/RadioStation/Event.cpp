//
// Created by damo on 1/25/16.
//

#include "Event.h"



empathy::radio::Event::Event(std::string action):
        action(action) ,
        intData(),
        broadcaster(nullptr),
        strData(),
        doubleData(),
        jsonData()
{


}

empathy::radio::Event::Event(const empathy::radio::Event &event) :
        action(event.action),
        intData(event.intData),
        broadcaster(event.broadcaster),
        strData(event.strData),
        doubleData(event.doubleData),
        jsonData(event.jsonData) {
}
