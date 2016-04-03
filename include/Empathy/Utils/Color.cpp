//
// Created by damo on 2/5/16.
//

#include "Color.h"

Color::Color(GLfloat r,GLfloat g, GLfloat b, GLfloat a):r(r),g(g),b(b),a(a) {


}

void Color::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    setR(r);
    setG(g);
    setB(b);
    setA(a);
}

void Color::setColor(Color *color) {
    setR(color->r);
    setG(color->g);
    setB(color->b);
    setA(color->a);
}

void Color::decodeJson(std::string key, cJSON *value) {
    if(key=="colorRed"){
        setR(value->valuedouble);
    }else if(key=="colorGreen"){
        setG(value->valuedouble);
    }else if(key=="colorBlue"){
        setB(value->valuedouble);
    }else if(key=="colorAlpha"){
        setA(value->valuedouble);
    }
}
