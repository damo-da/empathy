//
// Created by damo on 1/28/16.
//


#include "MathWave_Sine.h"
#include <cmath>
using namespace std;
GLfloat MathWave_Sine::getY(GLfloat x) {
//    cout<<"HI"<<sin(x*getPeriodConstant())<<getPeriodConstant()<<endl;
    return sin(x*getPeriodConstant());
}

void MathWave_Sine::init() {
    LifeEvent_MathWave::init();
    cout<<"init called"<<endl;
    setPeriod(0.2f);
}

MathWave_Sine::MathWave_Sine(GLfloat period)
        :period(period)
{

}

MathWave_Sine::MathWave_Sine():period(0.1f) {

}
