//
// Created by damo on 2/5/16.
//

#ifndef EMPATHY_LIFEEVENT_CWAVE_DATA_H
#define EMPATHY_LIFEEVENT_CWAVE_DATA_H

#define EMPATHY_CWAVE_MAXIMUM_DISTANCE 2.25

#include <math.h>

#include "../../Utils/Color.h"
#include "../../PureMath/include.h"
#include <vector>
#include "../LifeEvent.h"

namespace empathy{
    namespace life_event {
        class CWave_data : public LifeEvent, public Color, public pure_math::Wave {

        public:
            //constructors
            CWave_data();

        private:

            GLuint VAO;
            GLuint VBO;

            std::vector<GLfloat> vertices;
        public:
            virtual void onInit() override;

        protected:
            virtual void onRun(GLfloat delTime) override;


        public:
            virtual void decodeJson(std::string key, cJSON *value) override;

        public:
            virtual void onDestroy() override;

            virtual void draw() override;
        };
    }
}


#endif //EMPATHY_LIFEEVENT_CWAVE_DATA_H
