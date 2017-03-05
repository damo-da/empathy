//
// Created by geek on 4/6/16.
//

#include "../Utils/string_utils.h"
#include "linear_moonlight.h"

void empathy_linear::Linear_MoonLight::init() {
    empathy::moonlight::MoonLight::init();
}

void empathy_linear::Linear_MoonLight::terminate() {
    empathy::moonlight::MoonLight::terminate();
}

void empathy_linear::Linear_MoonLight::playKeyboard(empathy::moonlight::BasicNote note) {
    empathy::moonlight::MoonLight::playKeyboard(note);

    musicalKeyboardEvents.push(note);
}

void empathy_linear::Linear_MoonLight::play(std::string id, bool repeat) {
    empathy::moonlight::MoonLight::play(id, repeat);

    events.push(id);

}


empathy_linear::Linear_MoonLight::Linear_MoonLight() :
        empathy::moonlight::MoonLight(),
        musicalKeyboardEvents(),
        events()
{

}

std::stack<empathy::moonlight::BasicNote> empathy_linear::Linear_MoonLight::getMusicalKeyboardEvents() {
    std::stack<empathy::moonlight::BasicNote> ret;
    while(!musicalKeyboardEvents.empty()){
        ret.push(musicalKeyboardEvents.top());
        musicalKeyboardEvents.pop();
    }
    return ret;
}

std::stack<std::string> empathy_linear::Linear_MoonLight::getMusicalEvents() {
    std::stack<std::string> ret;
    while(!events.empty()){
        ret.push(events.top());
        events.pop();
    }
    return ret;
}
