//
// Created by damo on 2/5/16.
//

#include "Wave.h"

empathy::pure_math::Wave::Wave():
        centerX(0.0f),
        centerY(0.0f),
        frequency(1.95f),
        waveLength(0.08f),
        amplitude(1.0f),
        dampingConst(1.0f),
        initialPhase(M_PI_2)
{


}

void empathy::pure_math::Wave::decodeJson(std::string key, cJSON *value) {
    if(key=="frequency"){
        setFrequency(value->valuedouble);
    }else if(key=="wavelength"){
        setWaveLength(value->valuedouble);
    }else if(key=="centerX"){
        setCenterX(value->valuedouble);
    }else if(key=="centerY"){
        setCenterY(value->valuedouble);
    }else if(key=="damping"){
        setDampingConst(value->valuedouble);
    }else if(key=="initialPhase"){
        setInitialPhase(value->valuedouble);
    }
}
