//
// Created by damo on 1/28/16.
//


#include "MathWave_Sine.h"
#include <cmath>
using namespace std;
GLfloat MathWave_Sine::getY(GLfloat theta) {
//    cout<<"HI"<<sin(x*getPeriodConstant())<<getPeriodConstant()<<endl;
    return sin(theta*getPeriodConstant());
}

void MathWave_Sine::onInit() {
    LifeEvent_MathWave::onInit();

    setPeriod(0.2f);
}

MathWave_Sine::MathWave_Sine(GLfloat period)
        :period(period)
{

}

MathWave_Sine::MathWave_Sine():period(0.1f) {

}
