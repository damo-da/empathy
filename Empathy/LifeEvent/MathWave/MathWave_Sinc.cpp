//
// Created by damo on 1/28/16.
//

#include "MathWave_Sinc.h"
#include "MathWave_Sine.h"
#include <cmath>

#include <iostream>
using namespace std;
GLfloat MathWave_Sinc::getY(GLfloat x) {

    return MathWave_Sine::getY(x)/(x*getPeriodConstant());
}

void MathWave_Sinc::onInit() {
    MathWave_Sine::onInit();

    setPeriod(0.8f);
}
