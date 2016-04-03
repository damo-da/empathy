//
// Created by damo on 2/3/16.
//

#include "FadeInOut.h"

void empathy::life_event::FadeInOut::onDestroy() {
    LifeEvent::onDestroy();
}

void empathy::life_event::FadeInOut::onInit() {
    LifeEvent::onInit();


}

void empathy::life_event::FadeInOut::onCreate(GLfloat delTime) {
    if(getTimeSinceCreate()>1.0f)
        doneCreating();
}

void empathy::life_event::FadeInOut::onRun(GLfloat delTime) {
    if(getTimeSinceRun()>1.0f)
        doneRunning();
}

void empathy::life_event::FadeInOut::onFinish(GLfloat delTime) {
    if(getTimeSinceFinish()>1.0f)
        doneFinishing();


}

GLfloat empathy::life_event::FadeInOut::getX() {
    return 0;
}

GLfloat empathy::life_event::FadeInOut::getY() {
    return 0;
}
