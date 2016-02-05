//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_LIFEEVENT_CWAVE_DATA_H
#define EMPATHY_LIFEEVENT_CWAVE_DATA_H


#include <math.h>
#include "../life_event.hpp"
#include "../../Utils/Color.h"
#include <vector>
class LifeEvent_CWave_data : public LifeEvent , public Color{

public:
    //constructors
    LifeEvent_CWave_data(GLfloat, GLfloat);


    GLfloat getFrequency(){return frequency;}
    GLfloat getWavelength(){return waveLength;}
    void setFrequency(GLfloat f){this->frequency=f;}
    void setWaveLength(GLfloat w){this->waveLength=w;}

    GLfloat getWaveSpeed(){return getFrequency()*getWavelength();}
    GLdouble getAngularMomentum(){return M_2_PI*getFrequency();}
    GLfloat getTimePeriod(){return 1.0f/getFrequency();}

    GLfloat getRadius()const {return radius;}
private:
    GLfloat frequency, waveLength;

    GLfloat centerX;
    GLfloat centerY;

    GLfloat radius;

    GLuint VAO;
    GLuint VBO;

    std::vector<GLfloat> vertices;
public:
    virtual void onInit() override;

protected:
    virtual void onRun(GLfloat delTime) override;

public:
    virtual void onDestroy() override;

    virtual void draw() override;
};


#endif //EMPATHY_LIFEEVENT_CWAVE_DATA_H
