//
// Created by damo on 1/28/16.
//

#include "MathWave_Sinc.h"
#include "MathWave_Sine.h"
#include <cmath>

#include <iostream>
using namespace std;
GLfloat empathy::life_event::MathWave_Sinc::getY(GLfloat theta) {

    return empathy::life_event::MathWave_Sine::getY(theta)/(theta*getPeriodConstant());
}

void empathy::life_event::MathWave_Sinc::onInit() {
    empathy::life_event::MathWave_Sine::onInit();

    setPeriod(0.8f);
}
