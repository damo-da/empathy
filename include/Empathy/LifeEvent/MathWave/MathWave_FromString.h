#ifndef EMPATHY_MATHWAVE_FROMSTRING_H
#define EMPATHY_MATHWAVE_FROMSTRING_H

#include "MathWave.h"

namespace empathy {
    namespace life_event {

        class MathWave_FromString : public MathWave {

        public:
            virtual GLfloat getY(GLfloat) override;
            virtual GLfloat getX(GLfloat) override;
        };
    }
}


#endif //EMPATHY_MATHWAVE_FROMSTRING_H
