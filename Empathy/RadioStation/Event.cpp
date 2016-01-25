//
// Created by damo on 1/25/16.
//

#include "Event.h"



Event::Event(std::string action):action(action) {
    name="Event ";
}

std::string Event::LIFE_EVENT_WAVE_COMPLETE="LIFE_EVENT_WAVE_COMPLETE";
std::string Event::INPUT_KEY_PRESS="INPUT_KEY_PRESS";
std::string Event::INPUT_KEY_RELEASE="INPUT_KEY_RELEASE";
