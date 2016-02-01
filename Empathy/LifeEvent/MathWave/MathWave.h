//
// Created by damo on 1/27/16.
//

#ifndef EMPATHY_MATHWAVE_H
#define EMPATHY_MATHWAVE_H


#include "../life_event.hpp"
#include <vector>

#define EMPATHY_LIFE_EVENT_MATH_WAVE_STARTED_DESTROYING "EMPATHY_LIFE_EVENT_MATH_WAVE_STARTED_DESTROYING"
#define EMPATHY_LIFE_EVENT_MATH_WAVE_DESTROYED "EMPATHY_LIFE_EVENT_MATH_WAVE_DESTROYED"

class LifeEvent_MathWave : public LifeEvent{
public:
    void draw() override;

    void onDestroy() override;

    virtual void onInit() override ;


    void setZoomY(GLfloat zoomY) {
        LifeEvent_MathWave::zoomY = zoomY;
    }

public:
    LifeEvent_MathWave(bool horizontal);
    LifeEvent_MathWave();

    void setColor(GLfloat, GLfloat, GLfloat, GLfloat);

    bool isHorizontal(){return horizontal;}

    virtual GLfloat getY(GLfloat x)=0;

    void setHorizontal(bool horizontal) {
        LifeEvent_MathWave::horizontal = horizontal;
    }

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

protected:
    virtual void onRun(GLfloat delTime) override;

    virtual void onCreate(GLfloat delTime) override;

    virtual void onFinish(GLfloat delTime) override;

    GLfloat getStartX();
    GLfloat getEndX();

private:
    void calcVertices();

    bool horizontal;

    GLfloat head;//the starting point for the initialmost x
    GLfloat tail;//the ending poing for the finalmost x

    GLfloat speed; //the speed of the wave
    GLfloat length; //the length of the wave
    GLfloat zoomX; //the zoom level of the wave
    GLfloat zoomY; //
    GLfloat offsetX;
    GLfloat offsetY;
    GLfloat diff;
    GLfloat pencilSize;

    GLuint VAO,VBO;
    std::vector<GLfloat> vertices;

    std::vector<GLfloat> color;//in rgba
};


#endif //EMPATHY_MATHWAVE_H
