//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_WAVE_H
#define EMPATHY_WAVE_H


#include <GL/glew.h>
#include <math.h>

class Wave {
public:
    Wave();
    GLfloat getFrequency(){return frequency;}
    GLfloat getWavelength(){return waveLength;}
    void setFrequency(GLfloat f){this->frequency=f;}
    void setWaveLength(GLfloat w){this->waveLength=w;}

    GLfloat getWaveSpeed(){return getFrequency()*getWavelength();}
    GLdouble getAngularMomentum(){return M_2_PI*getFrequency();}
    GLfloat getTimePeriod(){return 1.0f/getFrequency();}


    GLfloat getCenterX() const {
        return centerX;
    }
    void setCenter(GLfloat x,GLfloat y){setCenterX(x);setCenterY(y);}
    void setCenterX(GLfloat x){centerX=x;};
    void setCenterY(GLfloat y){centerY=y;};

    GLfloat getCenterY() const {
        return centerY;
    }

private:
    GLfloat frequency, waveLength;

    GLfloat centerX;
    GLfloat centerY;
};


#endif //EMPATHY_WAVE_H
