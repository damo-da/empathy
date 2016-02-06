//
// Created by damo on 1/27/16.
//

#ifndef EMPATHY_MATHWAVE_H
#define EMPATHY_MATHWAVE_H


#include "../life_event.hpp"
#include "../../Utils/Color.h"
#include <vector>

#define EMPATHY_LIFE_EVENT_MATH_WAVE_STARTED_DESTROYING "EMPATHY_LIFE_EVENT_MATH_WAVE_STARTED_DESTROYING"
#define EMPATHY_LIFE_EVENT_MATH_WAVE_DESTROYED "EMPATHY_LIFE_EVENT_MATH_WAVE_DESTROYED"

class LifeEvent_MathWave : public LifeEvent,public Color{
public:
    virtual GLfloat getY(GLfloat theta)=0;
    virtual GLfloat getX(GLfloat theta);

public:
    void draw() override;

    void onDestroy() override;

    virtual void onInit() override ;

    void setZoomY(GLfloat zoomY) {
        LifeEvent_MathWave::zoomY = zoomY;
    }

public:
    LifeEvent_MathWave();


    void render(std::vector<GLfloat> &vertices);

    GLfloat getDiff() {
        return diff;
    }

    void setDiff(GLfloat diff) {
        LifeEvent_MathWave::diff = diff;
    }

    GLfloat getHead() const {
        return head;
    }

    void setHead(GLfloat head) {
        LifeEvent_MathWave::head = head;
    }


    GLfloat getTail() const {
        return tail;
    }

    void setTail(GLfloat tail) {
        LifeEvent_MathWave::tail = tail;
    }

    GLfloat getSpeed() const {
        return speed;
    }

    void setSpeed(GLfloat speed) {
        LifeEvent_MathWave::speed = speed;
    }

    GLfloat getLength() const {
        return length;
    }

    void setLength(GLfloat length) {
        LifeEvent_MathWave::length = length;
    }

    GLfloat getZoomX() const {
        return zoomX;
    }

    void setZoomX(GLfloat zoomX) {
        LifeEvent_MathWave::zoomX = zoomX;
    }

    GLfloat getZoomY() const {
        return zoomY;
    }

    GLfloat getOffsetX() const {
        return offsetX;
    }

    void setOffsetX(GLfloat offsetX) {
        LifeEvent_MathWave::offsetX = offsetX;
    }

    GLfloat getOffsetY() const {
        return offsetY;
    }

    void setOffsetY(GLfloat offsetY) {
        LifeEvent_MathWave::offsetY = offsetY;
    }

    GLfloat getPencilSize() const {
        return pencilSize;
    }

    void setPencilSize(GLfloat pencilSize) {
        LifeEvent_MathWave::pencilSize = pencilSize;
    }


    GLfloat getRotationAngle() const {
        return rotationAngle;
    }

    void setRotationAngle(GLfloat rotationAngle) {
        LifeEvent_MathWave::rotationAngle = rotationAngle;
    }

protected:
    virtual void onRun(GLfloat delTime) override;

    virtual void onCreate(GLfloat delTime) override;

    virtual void onFinish(GLfloat delTime) override;

    GLfloat getStartTheta();
    GLfloat getEndTheta();

private:
    void calcVertices();

    GLfloat head;//the starting point for the initialmost theta
    GLfloat tail;//the ending poing for the finalmost theta

    GLfloat speed; //the speed of the wave
    GLfloat length; //the length of the wave
    GLfloat zoomX; //the zoom level of the wave
    GLfloat zoomY; //
    GLfloat offsetX;
    GLfloat offsetY;
    GLfloat diff;
    GLfloat pencilSize;
    GLfloat rotationAngle;

    GLuint VAO,VBO;
    std::vector<GLfloat> vertices;
};


#endif //EMPATHY_MATHWAVE_H
