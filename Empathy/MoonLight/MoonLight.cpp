//
// Created by damo on 1/29/16.
//

#include "MoonLight.h"

using namespace std;

void empathy::moonlight::MoonLight::play(string id) {
    play(id,false);
}

void empathy::moonlight::MoonLight::play(string id, bool repeat) {

}


empathy::moonlight::MoonLight::MoonLight():Subscriber()
{

}

void empathy::moonlight::MoonLight::init() {
//    listen(EMPATHY_AUDIO_PLAY);
    listen(EMPATHY_AUDIO_PLAY_KEYBOARD);
}

void empathy::moonlight::MoonLight::onReceiveEvent(empathy::radio::Event &event) {
    empathy::radio::Subscriber::onReceiveEvent(event);
    if(event.action == EMPATHY_AUDIO_PLAY){
        std::string key=event.getString(EMPATHY_AUDIO_PLAY);
        bool repeat=event.getInt(EMPATHY_AUDIO_SHOULD_REPEAT);
        play(key,repeat);
    }else if(event.action==EMPATHY_AUDIO_PLAY_KEYBOARD){
        std::string key=event.getString(EMPATHY_AUDIO_PLAY_KEYBOARD);
        playKeyboard(key);
    }


}


void empathy::moonlight::MoonLight::terminate() {

}
