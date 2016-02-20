//
// Created by damo on 2/1/16.
//

#ifndef EMPATHY_MATHWAVE_LINE_H
#define EMPATHY_MATHWAVE_LINE_H


#include "MathWave.h"
namespace empathy {
    namespace life_event {
        class MathWave_Line : public LifeEvent_MathWave {

        public:
            virtual GLfloat getY(GLfloat) override;
        };
    }
}


#endif //EMPATHY_MATHWAVE_LINE_H
