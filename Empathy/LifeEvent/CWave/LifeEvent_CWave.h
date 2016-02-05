//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_LIFEEVENT_CWAVE_H
#define EMPATHY_LIFEEVENT_CWAVE_H


#include <math.h>
#include "../LifeEvent_Collection.h"

#define EMPATHY_LIFE_EVENT_CWAVE_CREATE_NEW_WAVE 0
#define EMPATHY_LIFE_EVENT_CWAVE_PERIOD_COMPLETE "EMPATHY_LIFE_EVENT_CWAVE_PERIOD_COMPLETE"

class LifeEvent_CWave : public LifeEvent_Collection {

public:
    LifeEvent_CWave();
    virtual void passTime(GLfloat delTime) override;

protected:
    virtual void onInit() override;


public:
    //constructors
    LifeEvent_CWave(GLfloat, GLfloat);

    void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);

    GLfloat getFrequency(){return frequency;}
    GLfloat getWavelength(){return waveLength;}
    void setFrequency(GLfloat f){this->frequency=f;}
    void setWaveLength(GLfloat w){this->waveLength=w;}

    GLfloat getWaveSpeed(){return getFrequency()*getWavelength();}
    GLdouble getAngularMomentum(){return M_2_PI*getFrequency();}
    GLfloat getTimePeriod(){return 1.0f/getFrequency();}

private:
    GLfloat frequency, waveLength;

    std::vector<GLfloat> color;//in rgba

    GLfloat centerX;
    GLfloat centerY;

    bool shouldCreateNewWave;
public:
    virtual void onReceiveEvent(Event &event) override;
};


#endif //EMPATHY_LIFEEVENT_CWAVE_H
