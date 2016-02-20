//
// Created by damo on 1/25/16.
//

#include "Event.h"



empathy::radio::Event::Event(std::string action):
        action(action) ,
        intData(),
        broadcaster(nullptr),
        strData(){


}