#ifndef EMPATHY_MATHWAVE_FROMSTRING_H
#define EMPATHY_MATHWAVE_FROMSTRING_H

#include <muParser.h>
#include "MathWave.h"

namespace empathy {
    namespace life_event {

        class MathWave_FromString : public MathWave {

        mu::Parser xParser,yParser;
        public:

            MathWave_FromString();

            virtual GLfloat getY(GLfloat) override;
            virtual GLfloat getX(GLfloat) override;

            virtual void decodeJson(const std::string key, cJSON *value);

        };
    }
}


#endif //EMPATHY_MATHWAVE_FROMSTRING_H
