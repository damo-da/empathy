//
// Created by geek on 4/10/16.
//

#ifndef DEMPATHY_LINEAR_BACKGROUND_TRANSITION_H
#define DEMPATHY_LINEAR_BACKGROUND_TRANSITION_H


#include "../../Utils/Color.h"

namespace empathy{
    namespace life_event{
        class Background_Transition{
        public:
            Background_Transition(Color color,GLfloat duration);

            Color color;
            GLfloat current_transition_time;
            GLfloat transition_duration;



            Background_Transition();
        };
    }
}


#endif //DEMPATHY_LINEAR_BACKGROUND_TRANSITION_H
