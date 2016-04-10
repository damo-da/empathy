//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_COLOR_H
#define EMPATHY_COLOR_H


#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "../Libs/cJSON/cJSON.h"

/* The color class to hold a RGBA color value. */
class Color {
public:
    void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a=1.0f);

    Color(GLfloat r=1.0f,GLfloat g=1.0f,GLfloat b=1.0f,GLfloat a=1.0f);

    Color(Color * color);

    /* Something like a "pointer" copy constructor. */
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


    static Color mix(Color * color1,Color * color2,GLfloat ratio);

    /* Apply color from JSON. */
    virtual void decodeJson(std::string key,cJSON* value);

    std::string toString();
private:
    GLfloat r,g,b,a;
};


#endif //EMPATHY_COLOR_H
