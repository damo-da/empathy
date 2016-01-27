//
// Created by damo on 1/27/16.
//

#ifndef EMPATHY_LIFEEVENT_SINEWAVE_H
#define EMPATHY_LIFEEVENT_SINEWAVE_H

#include <iostream>
#include <vector>
#include "../life_event.hpp"

class LifeEvent_SineWave : public LifeEvent{
public:
    virtual void draw(GLuint shaderProgram) override;

    virtual void destroy() override;

    virtual void init();

    virtual void passTime(GLfloat lfloat) override;

    LifeEvent_SineWave(GLfloat length,GLfloat baseValue,GLfloat amplitude,GLfloat speed,bool horizontal);
    LifeEvent_SineWave(GLfloat length,GLfloat baseValue,GLfloat amplitude,GLfloat speed);

    int getLength(){return length;}
    bool isHorizontal(){return horizontal;}

    void setColor(GLfloat, GLfloat, GLfloat, GLfloat);

    static GLfloat diff;
private:
    GLfloat head;

    const GLfloat length;

    const GLfloat speed;

    const GLfloat baseValue;

    const GLfloat amplitude;

    const bool horizontal;

    GLuint VAO,VBO;
    std::vector<GLfloat> vertices;

    std::vector<GLfloat> color;//in rgba
};


#endif //EMPATHY_LIFEEVENT_SINEWAVE_H
