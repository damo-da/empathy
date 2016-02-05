//
// Created by damo on 2/5/16.
//

#include "LifeEvent_CWave.h"

LifeEvent_CWave::LifeEvent_CWave() : LifeEvent_Collection() {

}

void LifeEvent_CWave::onRun(GLfloat delTime) {
    LifeEvent_Collection::onRun(delTime);
}

void LifeEvent_CWave::onCreate(GLfloat delTime) {
    LifeEvent_Collection::onCreate(delTime);
}

void LifeEvent_CWave::onFinish(GLfloat delTime) {
    LifeEvent_Collection::onFinish(delTime);
}
