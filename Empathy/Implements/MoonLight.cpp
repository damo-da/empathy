//
// Created by damo on 1/29/16.
//


#include "MoonLight.h"
#include <vector>
using namespace std;

void MoonLight::play(string id) {
    play(id,false);
}

void MoonLight::play(string id, bool repeat) {

}


MoonLight::MoonLight():Subscriber()
{

}

void MoonLight::init() {
//    listen(EMPATHY_AUDIO_PLAY);
    listen(EMPATHY_AUDIO_PLAY_KEYBOARD);
}

void MoonLight::onReceiveEvent(Event &event) {
    Subscriber::onReceiveEvent(event);
    if(event.action == EMPATHY_AUDIO_PLAY){
        std::string key=event.getString(EMPATHY_AUDIO_PLAY);
        bool repeat=event.getInt(EMPATHY_AUDIO_SHOULD_REPEAT);
        play(key,repeat);
    }else if(event.action==EMPATHY_AUDIO_PLAY_KEYBOARD){
        std::string key=event.getString(EMPATHY_AUDIO_PLAY_KEYBOARD);
        playKeyboard(key);
    }


}


void MoonLight::terminate() {

}
