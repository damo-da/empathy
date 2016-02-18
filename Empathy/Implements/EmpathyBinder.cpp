//
// Created by damo on 1/25/16.
//

#include "EmpathyBinder.h"

bool EmpathyBinder::shouldTerminate() {
    return false;
}


void EmpathyBinder::terminate() {

}

EmpathyBinder::EmpathyBinder():brains() {

}

void EmpathyBinder::addBrain(Brain *brain) {
    brains.push_back(brain);
}
