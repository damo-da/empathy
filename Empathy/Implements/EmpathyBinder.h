//
// Created by damo on 1/25/16.
//

#ifndef EMPATHY_NONNATIVEEMPATHY_H
#define EMPATHY_NONNATIVEEMPATHY_H

#include <GL/glew.h>
#include "MoonLight.h"
#include "../You/Brain/Brain.h"
#include "../empathy.hpp"
#include <vector>
class Empathy;
class Brain;
class EmpathyBinder {
    MoonLight * moonLight;
public:

    MoonLight *getMoonLight() const {
        return moonLight;
    }

    void setMoonLight(MoonLight *moonLight) {
        EmpathyBinder::moonLight = moonLight;
    }

    //The instance for the Empathy app
    Empathy * empathy;

    virtual void init()=0;

    virtual GLfloat  getTime()=0;
    virtual void terminate()=0;
    virtual void run()=0;

    EmpathyBinder();


private:

};


#endif //EMPATHY_NONNATIVEEMPATHY_H
