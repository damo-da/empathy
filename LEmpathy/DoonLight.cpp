//
// Created by damo on 1/29/16.
//

#include "DoonLight.h"

#include <iostream>
using namespace std;
void DoonLight::play(std::string id, bool repeat) {
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

void DoonLight::init() {
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

void DoonLight::terminate() {
    MoonLight::terminate();

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

//    engine->setSoundVolume(0.05f);
}


std::string DoonLight::BASE="./assets/audio/";
std::string DoonLight::KEYBOARD_BASE= DoonLight::BASE + "keyboard/";

void DoonLight::playKeyboard(string key) {


    try{
        std::string file=KEYBOARD_BASE+key+".ogg";


        engine->play2D(file.c_str());

    }catch (int i){
        return;
    }
}

DoonLight::DoonLight(): MoonLight() {

}
