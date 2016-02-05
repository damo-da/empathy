//
// Created by damo on 2/5/16.
//

#include "Color.h"

Color::Color():r(1.0f),g(1.0f),b(1.0f),a(1.0f) {


}

void Color::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    setR(r);
    setG(g);
    setB(b);
    setA(a);
}

void Color::setColor(GLfloat r, GLfloat g, GLfloat b) {
    setR(r);
    setG(g);
    setB(b);
    setA(1.0f);
}

void Color::setColor(Color *color) {
    setR(color->r);
    setG(color->g);
    setB(color->b);
    setA(color->a);
}
