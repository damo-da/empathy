//
// Created by damo on 1/28/16.
//


#include "MathWave_Sine.h"
#include <cmath>
using namespace std;
GLfloat empathy::life_event::MathWave_Sine::getY(GLfloat theta) {
//    cout<<"HI"<<sin(x*getPeriodConstant())<<getPeriodConstant()<<endl;
    return sin(theta*getPeriodConstant()+getThetaOffset());
}

void empathy::life_event::MathWave_Sine::onInit() {
    empathy::life_event::LifeEvent_MathWave::onInit();


}

empathy::life_event::MathWave_Sine::MathWave_Sine(GLfloat period) :
        LifeEvent_MathWave(),
        period(period),
        thetaOffset(0.0f)
{

}

empathy::life_event::MathWave_Sine::MathWave_Sine():
        LifeEvent_MathWave(),
        period(0.1f),
        thetaOffset(0.0f)
{

}

void empathy::life_event::MathWave_Sine::decodeJson(std::string key, cJSON *value) {
    empathy::life_event::LifeEvent_MathWave::decodeJson(key, value);

    if(key=="period"){
        setPeriod(value->valuedouble);
    }else if(key=="sine_thetaOffset"){
        setThetaOffset(value->valuedouble);
    }
}
