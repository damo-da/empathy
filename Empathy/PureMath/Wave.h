//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_WAVE_H
#define EMPATHY_WAVE_H


#include <GL/glew.h>
#include <math.h>
#include <iostream>
#include "../Libs/cJSON/cJSON.h"

using namespace std;

class Wave {
public:
    Wave();
    GLfloat getFrequency()const{return frequency;}

    void setFrequency(GLfloat f){this->frequency=f;}
    void setWaveLength(GLfloat w){this->waveLength=w;}

    GLfloat getWaveSpeed()const {return getFrequency()*getWaveLength();}
    GLdouble getAngularMomentum()const {return M_2_PI*getFrequency();}
    GLfloat getTimePeriod()const{return 1.0f/getFrequency();}


    GLfloat getCenterX() const {
        return centerX;
    }
    void setCenter(GLfloat x,GLfloat y){setCenterX(x);setCenterY(y);}
    void setCenterX(GLfloat x){centerX=x;};
    void setCenterY(GLfloat y){centerY=y;};

    GLfloat getCenterY() const {
        return centerY;
    }

    void decodeJson(std::string key,cJSON* value);

    GLfloat getAmplitude() const {
        return amplitude;
    }

    void setAmplitude(GLfloat amplitude) {
        Wave::amplitude = amplitude;
    }


    GLfloat getWaveLength() const {
        return waveLength;
    }

    GLfloat getAmplitudeAt(GLfloat distance)const {
        GLfloat time=getTime()-distance/getWaveSpeed();

        return getAmplitude()*sin(getAngularMomentum()*time + getInitialPhase())*exp(-getDampingConst()*distance);
    }


    GLfloat getDampingConst() const {
        return dampingConst;
    }

    void setDampingConst(GLfloat dampingConst) {
        Wave::dampingConst = dampingConst;
    }


    GLfloat getTime() const {
        return time;
    }

    void setTime(GLfloat time) {
        Wave::time = time;
    }

    void setInitialPhase(GLfloat theta){
        Wave::initialPhase=theta;
    }
    GLfloat getInitialPhase()const{return initialPhase;}
private:
    GLfloat frequency;
    GLfloat waveLength;

    GLfloat time;

    GLfloat amplitude;//the total amplitude of the wav]e

    GLfloat dampingConst;

    GLfloat initialPhase;

    GLfloat centerX;
    GLfloat centerY;
};


#endif //EMPATHY_WAVE_H
