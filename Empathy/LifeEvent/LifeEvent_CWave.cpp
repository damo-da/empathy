//
// Created by damo on 2/5/16.
//

#include "LifeEvent_CWave.h"

LifeEvent_CWave::LifeEvent_CWave() : LifeEvent_Collection() {

}

void LifeEvent_CWave::onInit() {
    LifeEvent_Collection::onInit();

}


void LifeEvent_CWave::passTime(GLfloat delTime) {
    LifeEvent_Collection::passTime(delTime);
}
