//
// Created by geek on 4/10/16.
//

#include "Background.h"
using namespace std;

void empathy::life_event::Background::onRun(GLfloat delTime) {
    Color mixed;

    if(transitions.size()>1){
        GLfloat ratio=transitions[0].current_transition_time / transitions[0].transition_duration;

        mixed=Color::mix(&transitions[0].color,&transitions[1].color,ratio);

        transitions[0].current_transition_time += delTime;

        if(transitions[0].current_transition_time>transitions[0].transition_duration){
            transitions.erase(transitions.begin());
            last_completion_time=getTimeSinceCreate();
        }

        setColor(&mixed);

    }

}

void empathy::life_event::Background::onInit() {
    LifeEvent::onInit();

    setColor(0.1f,0.1f,0.2f,0.0f);
    addTransition(this,0.1f);
}

void empathy::life_event::Background::draw() {


    glClearColor(getR(), getG(),getB(),getA());
//
    glClear(GL_COLOR_BUFFER_BIT );
}

void empathy::life_event::Background::onCreate(GLfloat delTime) {
    LifeEvent::onCreate(delTime);
}


empathy::life_event::Background::Background() :
        LifeEvent(),
        Color(),
        last_completion_time(0),
        transitions()

{
    transitions.push_back(Background_Transition(Color(this),1.0));
}


void empathy::life_event::Background::decodeJson(std::string key, cJSON *value) {
    LifeEvent::decodeJson(key, value);
    Color::decodeJson(key,value);

    if(key=="background_transition"){

    }
}

void empathy::life_event::Background::addTransition(Color color, GLfloat duration) {
    transitions.push_back(Background_Transition(color,duration));
}

