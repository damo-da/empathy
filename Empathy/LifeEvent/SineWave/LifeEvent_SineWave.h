//
// Created by damo on 1/27/16.
//

#ifndef EMPATHY_LIFEEVENT_SINEWAVE_H
#define EMPATHY_LIFEEVENT_SINEWAVE_H

#include <iostream>
#include <vector>
#include "../life_event.hpp"

#define EMPATHY_LIFE_EVENT_SINE_WAVE_STARTED_DESTROYING "EMPATHY_LIFE_EVENT_SINE_WAVE_STARTED_DESTROYING"
#define EMPATHY_LIFE_EVENT_SINE_WAVE_DESTROYED "EMPATHY_LIFE_EVENT_SINE_WAVE_DESTROYED"
class LifeEvent_SineWave : public LifeEvent{
public:
    virtual void draw(GLuint shaderProgram) override;

    virtual void destroy() override;

    virtual void init();

    virtual void passTime(GLfloat lfloat) override;

    LifeEvent_SineWave(GLfloat length,GLfloat baseValue,GLfloat amplitude,GLfloat speed,bool horizontal);
    LifeEvent_SineWave(GLfloat length,GLfloat baseValue,GLfloat amplitude,GLfloat speed);
    LifeEvent_SineWave();

    void setColor(GLfloat, GLfloat, GLfloat, GLfloat);

    static GLfloat diff;

    GLfloat getLength(){return length;}
    bool isHorizontal(){return horizontal;}
    GLfloat getBaseValue() const {
        return baseValue;
    }
    GLfloat getSpeed() const {
        return speed;
    }
    GLfloat getAmplitude() const {
        return amplitude;
    }
    GLfloat getPeriod() const {
        return period;
    }
    void setLength(GLfloat length) {
        this->length = length;
    }
    void setSpeed(GLfloat speed) {
        LifeEvent_SineWave::speed = speed;
    }
    void setBaseValue(GLfloat baseValue) {
        LifeEvent_SineWave::baseValue = baseValue;
    }
    void setHorizontal(bool horizontal) {
        LifeEvent_SineWave::horizontal = horizontal;
    }
    void setAmplitude(GLfloat amplitude) {
        LifeEvent_SineWave::amplitude = amplitude;
    }
    void setPeriod(GLfloat period) {
        LifeEvent_SineWave::period = period;
    }

private:
    GLfloat head;

    GLfloat length;

    GLfloat speed;

    GLfloat baseValue;

    GLfloat amplitude;

    bool startedDestroying;

public:
    GLfloat getHead() const {
        return head;
    }

    void setHead(GLfloat head) {
        LifeEvent_SineWave::head = head;
    }

private:
    bool horizontal;

    GLfloat period;

    GLuint VAO,VBO;
    std::vector<GLfloat> vertices;

    std::vector<GLfloat> color;//in rgba
};


#endif //EMPATHY_LIFEEVENT_SINEWAVE_H
