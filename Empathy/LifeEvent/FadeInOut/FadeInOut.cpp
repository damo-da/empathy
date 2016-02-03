//
// Created by damo on 2/3/16.
//

#include "FadeInOut.h"

void FadeInOut::onDestroy() {

}

void FadeInOut::onInit() {

}

void FadeInOut::onCreate(GLfloat delTime) {
    if(getTimeSinceCreate()>1.0f)
        doneCreating();
}

void FadeInOut::onRun(GLfloat delTime) {
    if(getTimeSinceRun()>1.0f)
        doneRunning();
}

void FadeInOut::onFinish(GLfloat delTime) {
    if(getTimeSinceFinish()>1.0f)
        doneFinishing();


}

GLfloat FadeInOut::getX() {
    return 0;
}

GLfloat FadeInOut::getY() {
    return 0;
}
