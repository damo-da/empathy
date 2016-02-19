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


}

MathWave_Sine::MathWave_Sine(GLfloat period) :
        LifeEvent_MathWave(),
        period(period)
{

}

MathWave_Sine::MathWave_Sine():
        LifeEvent_MathWave(),
        period(0.1f) {

}

void MathWave_Sine::decodeJson(std::string key, cJSON *value) {
    LifeEvent_MathWave::decodeJson(key, value);

    if(key=="period"){
        setPeriod(value->valuedouble);
    }
}
