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

Color Color::mix(Color *color1, Color *color2, GLfloat ratio) {
    Color mixed;

    mixed.setA(color2->getA()*ratio + color1->getA()*(1-ratio));
    mixed.setR(color2->getR()*ratio + color1->getR()*(1-ratio));
    mixed.setG(color2->getG()*ratio + color1->getG()*(1-ratio));
    mixed.setB(color2->getB()*ratio + color1->getB()*(1-ratio));

    return mixed;
}

Color::Color(Color *color) {
    this->setColor(color);
}

std::string Color::toString() {
    return "Color("
                   "r=>" + std::to_string(r)+", "
                   "g=>" + std::to_string(g)+", "
                   "b=>" + std::to_string(b)+", "
                   "a=>" + std::to_string(a)+")";

}









