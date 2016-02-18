//
// Created by damo on 1/25/16.
//

#include "EmpathyBinder.h"


EmpathyBinder::EmpathyBinder():
        brains(),
        moonLight(nullptr)
{
    empathy=new Empathy(this);
}

void EmpathyBinder::addBrain(Brain *brain) {
    brains.push_back(brain);
}
