//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_LIFEEVENT_CWAVE_H
#define EMPATHY_LIFEEVENT_CWAVE_H


#include "LifeEvent_Collection.h"

class LifeEvent_CWave : public LifeEvent_Collection {

public:
    LifeEvent_CWave();

protected:
    virtual void onInit() override;

protected:

public:
    virtual void passTime(GLfloat delTime) override;
};


#endif //EMPATHY_LIFEEVENT_CWAVE_H
