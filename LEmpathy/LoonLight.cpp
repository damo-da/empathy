//
// Created by damo on 1/29/16.
//

#include "LoonLight.h"

#include <iostream>
using namespace std;
void LoonLight::play(std::string id, bool repeat) {
    MoonLight::play(id, repeat);
    cout<<"Playing "<<id<<endl;
    try{
        std::string local=references[id];
        std::string file=BASE+local;

        if(local.size()>0)
            engine->play2D(file.c_str());

    }catch (int i){
        return;
    }

}

void LoonLight::init() {
    MoonLight::init();
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

void LoonLight::terminate() {
    MoonLight::terminate();

    cout<<"terminating loonlinght"<<endl;
    engine->drop(); // delete engine
}

void LoonLight::initIrr() {
    // start the sound engine with default parameters
    engine = createIrrKlangDevice();

    if (!engine)
    {
        printf("Could not startup engine\n");
    }

//    engine->setSoundVolume(0.05f);
}


std::string LoonLight::BASE="./assets/audio/";
std::string LoonLight::KEYBOARD_BASE=LoonLight::BASE+"keyboard/";

void LoonLight::playKeyboard(string key) {


    try{
        std::string file=KEYBOARD_BASE+key+".ogg";


        engine->play2D(file.c_str());

    }catch (int i){
        return;
    }
}
