//
// Created by damo on 2/6/16.
//

#ifndef EMPATHY_MATHWAVE_PARA_CIRCLE_H
#define EMPATHY_MATHWAVE_PARA_CIRCLE_H


#include "MathWave.h"
namespace empathy {
    namespace life_event {

        class MathWave_Para_Circle : public MathWave {

        public:
            virtual GLfloat getY(GLfloat x) override;

            virtual GLfloat getX(GLfloat theta) override;
        };
    }
}

#endif //EMPATHY_MATHWAVE_PARA_CIRCLE_H
