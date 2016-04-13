//
// Created by geek on 4/10/16.
//

#ifndef DEMPATHY_LINEAR_BACKGROUND_H
#define DEMPATHY_LINEAR_BACKGROUND_H

#include <iostream>
#include <vector>

#include "../../Utils/Color.h"
#include "../../empathy.h"
#include "../LifeEvent.h"
#include "Background_Transition.h"

namespace empathy{
    namespace life_event{

        class Background : public LifeEvent, public Color{
        public:
            std::vector<life_event::Background_Transition> transitions;
            GLfloat last_completion_time;

        protected:
        public:
        protected:
        public:
            virtual void onDestroy() override;

            virtual void onCreate(GLfloat delTime) override;

            virtual void decodeJson(std::string key, cJSON *value) override;

        public:
            Background();

            virtual void onRun(GLfloat delTime);

        public:
            virtual void onInit();

            virtual void draw();

            void addTransition(Color color, GLfloat d);
        };
    }


}



#endif //DEMPATHY_LINEAR_BACKGROUND_H
