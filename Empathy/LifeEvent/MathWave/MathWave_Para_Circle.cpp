//
// Created by damo on 2/6/16.
//

#include "MathWave_Para_Circle.h"
#include <math.h>

GLfloat empathy::life_event::MathWave_Para_Circle::getY(GLfloat theta) {
    return sin(theta);
}

GLfloat empathy::life_event::MathWave_Para_Circle::getX(GLfloat theta) {
    return cos(theta);
}
