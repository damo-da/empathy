//
// Created by geek on 4/6/16.
//

#include <Empathy/Utils/string_utils.h>
#include "Linear_MoonLight.h"

void Linear_MoonLight::init() {
    empathy::moonlight::MoonLight::init();
}

void Linear_MoonLight::terminate() {
    empathy::moonlight::MoonLight::terminate();
}

void Linear_MoonLight::playKeyboard(std::string key) {
    empathy::moonlight::MoonLight::playKeyboard(key);

    int pitch=str_to_int(key);

    bool sharp=str_has_character(key,'s') || str_has_character(key,'#');

    std::string main=str_to_lower(
            str_remove_character(
                    str_remove_character(
                            str_remove_character(key, int_to_single_char(pitch))
                            ,'s')
                    ,'#'));

    pitch -= 1;
    std::string final=main;
    if(pitch>0)final += int_to_str(pitch);
    if(sharp){
        final="#"+final;
    }

    std::string file=empathy::getAssetPath("audio/keyboard/music/"+final+".mp3");


    PlayableItem item(file,false);
    events.push(item);
}

void Linear_MoonLight::play(std::string id, bool repeat) {
    empathy::moonlight::MoonLight::play(id, repeat);

    PlayableItem item(id,repeat);
    events.push(item);

}


Linear_MoonLight::Linear_MoonLight() :
        MoonLight(),
        events()
{

}

std::stack<PlayableItem> Linear_MoonLight::getEvents() {
    std::stack<PlayableItem> ret;
    while(!events.empty()){
        ret.push(events.top());
        events.pop();
    }
    return ret;
}


PlayableItem::PlayableItem(std::string fileName, bool repeat):
        fileName(fileName),
        repeat(repeat)
{

}

