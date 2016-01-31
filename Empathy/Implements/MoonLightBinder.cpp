//
// Created by damo on 1/31/16.
//

#include "MoonLightBinder.h"

#include "MoonLight.h"
#include "../LifeEvent/Wave/wave.hpp"

void MoonLightBinder::init(MoonLight *moonLight) {
    moonLight->bind(EMPATHY_LIFE_EVENT_WAVE_CREST_COMPLETE,EMPATHY_AUDIO_WAVE_COMPLETE);
}
