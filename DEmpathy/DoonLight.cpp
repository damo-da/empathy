//
// Created by damo on 1/29/16.
//

#include "DoonLight.h"
#include "Empathy/Utils/string_utils.h"

#include "Empathy/global.h"

#include <iostream>
using namespace std;
void DoonLight::play(std::string id, bool repeat) {
    empathy::moonlight::MoonLight::play(id, repeat);
    cout<<"Playing "<<id<<endl;
    try{
        std::string local=references[id];
        std::string file=empathy::getAssetPath(local);

        if(local.size()>0)
            engine->play2D(file.c_str());

    }catch (int i){
        return;
    }

}

void DoonLight::init() {
    empathy::moonlight::MoonLight::init();
    initIrr();

    references=std::map<std::string,std::string>();

    references["0A"]="keyboard/0A.ogg";
//    references[EMPATHY_AUDIO_0A]="keyboard/0A.ogg";
//    references[EMPATHY_AUDIO_0B]="keyboard/0A.ogg";
//    references[EMPATHY_AUDIO_0B]="keyboard/0A.ogg";
//    references[EMPATHY_AUDIO_0B]="keyboard/0A.ogg";
//    references[EMPATHY_AUDIO_OB]="keyboard/0A.ogg";
//    references[EMPATHY_AUDIO_OB]="keyboard/0A.ogg";
//    references[EMPATHY_AUDIO_OB]="keyboard/0A.ogg";

}

void DoonLight::terminate() {
    empathy::moonlight::MoonLight::terminate();

    cout<<"terminating loonlinght"<<endl;
    engine->drop(); // delete engine
}

void DoonLight::initIrr() {
    // start the sound engine with default parameters
    engine = createIrrKlangDevice();

    if (!engine)
    {
        printf("Could not startup engine\n");
    }

    engine->setSoundVolume(0.4f);
}

void DoonLight::playKeyboard(string key) {
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
//    cout<<"Playing "<<final<<endl;
    try{
//        std::string file=KEYBOARD_BASE+key+".ogg";
        std::string file=empathy::getAssetPath("audio/keyboard/music/"+final+".mp3");
        cout<<"Playing audio"<<file<<endl;

        engine->play2D(file.c_str());

    }catch (int i){
        return;
    }
}

DoonLight::DoonLight(): empathy::moonlight::MoonLight() {

}
