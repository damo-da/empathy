//
// Created by damo on 1/29/16.
//

#ifndef EMPATHY_MOONLIGHT_H
#define EMPATHY_MOONLIGHT_H

#include "../RadioStation/Subscriber.h"
#include <map>

#define EMPATHY_AUDIO_WAVE_COMPLETE "EMPATHY_AUDIO_WAVE_COMPLETE"

class MoonLight : public Subscriber{
public:
    virtual void play(std::string id, bool repeat);
    void play(std::string id);

    MoonLight();

    virtual void init();
    virtual void terminate();

    virtual void onReceiveEvent(Event &event) override;

    void bind(std::string key,std::string value){
        bindings[key]=value;
    }

    bool repeats(std::string key);
private:
    const std::map<std::string, std::string> &getBindings() const {
        return bindings;
    }

private:
    std::map<std::string,std::string> bindings;
    std::map<std::string,bool> repeatingBindings;
};


#endif //EMPATHY_MOONLIGHT_H
