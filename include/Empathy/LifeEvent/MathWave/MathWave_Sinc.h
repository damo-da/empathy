//
// Created by damo on 1/28/16.
//

#ifndef EMPATHY_MATHWAVE_SINC_H_H
#define EMPATHY_MATHWAVE_SINC_H_H

#include "MathWave.h"
#include "MathWave_Sine.h"
namespace empathy{
    namespace life_event {
        class MathWave_Sinc : public MathWave_Sine {

        public:
            virtual GLfloat getY(GLfloat theta) override;

            virtual void onInit() override;
        };
    }
}
#endif //EMPATHY_MATHWAVE_SINC_H_H

