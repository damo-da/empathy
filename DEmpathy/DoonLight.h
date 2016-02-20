//
// Created by damo on 1/29/16.
//

#ifndef EMPATHY_LOONLIGHT_H
#define EMPATHY_LOONLIGHT_H

#include <map>
#include <iostream>
#include <irrKlang.h>

using namespace irrklang;

#include "../Empathy/MoonLight/MoonLight.h"

class DoonLight : public empathy::moonlight::MoonLight{
public:

    virtual void init() override;
    virtual void terminate() override;

    DoonLight();

private:
    ISoundEngine* engine;
    std::map<std::string,std::string> references;

    void initIrr();

protected:
    virtual void play(std::string id, bool repeat) override;
    virtual void playKeyboard(std::string string) override;

private:
    static std::string BASE;
    static std::string KEYBOARD_BASE;
};


#endif //EMPATHY_LOONLIGHT_H
