//
// Created by geek on 4/6/16.
//

#include "../Utils/string_utils.h"
#include "Linear_MoonLight.h"

void empathy_linear::Linear_MoonLight::init() {
    empathy::moonlight::MoonLight::init();
}

void empathy_linear::Linear_MoonLight::terminate() {
    empathy::moonlight::MoonLight::terminate();
}

void empathy_linear::Linear_MoonLight::playKeyboard(empathy::moonlight::BasicNote note) {
    empathy::moonlight::MoonLight::playKeyboard(note);

    events.push(note);
}

void empathy_linear::Linear_MoonLight::play(std::string id, bool repeat) {
    empathy::moonlight::MoonLight::play(id, repeat);



}


empathy_linear::Linear_MoonLight::Linear_MoonLight() :
        empathy::moonlight::MoonLight(),
        events()
{

}

std::stack<empathy::moonlight::BasicNote> empathy_linear::Linear_MoonLight::getEvents() {
    std::stack<empathy::moonlight::BasicNote> ret;
    while(!events.empty()){
        ret.push(events.top());
        events.pop();
    }
    return ret;
}
