//
// Created by geek on 4/10/16.
//

#include "Background_Transition.h"


empathy::life_event::Background_Transition::Background_Transition():
color(),
transition_duration(4.0f),
current_transition_time(0.0f)
{

}

empathy::life_event::Background_Transition::Background_Transition(Color color,GLfloat duration):
transition_duration(4.0f),
color(color),
current_transition_time(0.0f)
{

}








