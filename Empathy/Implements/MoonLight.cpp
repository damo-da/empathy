//
// Created by damo on 1/29/16.
//


#include "MoonLight.h"
#include <vector>
using namespace std;

void MoonLight::play(string id) {
    play(id,repeats(id));
}

void MoonLight::play(string id, bool repeat) {

}


MoonLight::MoonLight():
        bindings(),
        repeatingBindings()
{
    repeatingBindings[EMPATHY_AUDIO_WAVE_COMPLETE]=false;
}

void MoonLight::init() {
    //Get all keys
    map<string,string> binds=getBindings();
    vector<string> v;
    for(map<string,string>::iterator it = binds.begin(); it != binds.end(); ++it) {
        v.push_back(it->first);
    }

    //listen to all keys
    for(int i=0;i<v.size();i++){
        listen(v[i]);
    }


}

void MoonLight::onReceiveEvent(Event &event) {
    Subscriber::onReceiveEvent(event);

    string mEvent=bindings[event.action];

    play(mEvent);
}

bool MoonLight::repeats(std::string key) {
    try{
        return this->repeatingBindings[key];
    }catch (int i){
        return false;
    }
}

void MoonLight::terminate() {

}
