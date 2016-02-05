//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_COLOR_H
#define EMPATHY_COLOR_H


#include <GL/glew.h>
#include <iostream>
#include <vector>
class Color {
public:
    void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void setColor(GLfloat r, GLfloat g, GLfloat b);

    Color();

    void setColor(Color * color);


    GLfloat getR() const {
        return r;
    }

    void setR(GLfloat r) {
        Color::r = r;
    }

    GLfloat getG() const {
        return g;
    }

    void setG(GLfloat g) {
        Color::g = g;
    }

    GLfloat getB() const {
        return b;
    }

    void setB(GLfloat b) {
        Color::b = b;
    }

    GLfloat getA() const {
        return a;
    }

    void setA(GLfloat a) {
        Color::a = a;
    }

private:
    GLfloat r,g,b,a;
};


#endif //EMPATHY_COLOR_H
