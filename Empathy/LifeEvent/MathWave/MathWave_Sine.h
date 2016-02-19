//
// Created by damo on 1/28/16.
//

#include "MathWave.h"

#ifndef EMPATHY_MATHWAVE_SINE_H
#define EMPATHY_MATHWAVE_SINE_H

using namespace std;
class MathWave_Sine : public LifeEvent_MathWave{

public:
    virtual GLfloat getY(GLfloat theta) override;

    GLfloat getPeriod() const {
        return period;
    }

    void setPeriod(GLfloat period) {
        this->period = period;
    }

    GLfloat getPeriodConstant() const{
        return 2.0f/getPeriod();
    }


    GLfloat getThetaOffset() const {
        return thetaOffset;
    }

    void setThetaOffset(GLfloat thetaOffset) {
        MathWave_Sine::thetaOffset = thetaOffset;
    }

    virtual void onInit() override ;

    MathWave_Sine(GLfloat period);

    MathWave_Sine();

    virtual void decodeJson(std::string key, cJSON *value) override;

private:
    GLfloat thetaOffset;
    GLfloat period;
};

#endif //EMPATHY_MATHWAVE_SINE_H
