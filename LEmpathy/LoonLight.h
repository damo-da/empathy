//
// Created by damo on 1/29/16.
//

#ifndef EMPATHY_LOONLIGHT_H
#define EMPATHY_LOONLIGHT_H

#include <map>
#include <iostream>


#include <irrKlang.h>



using namespace irrklang;

#include "../Empathy/Implements/MoonLight.h"

class LoonLight : public MoonLight{
public:
    ISoundEngine* engine;

    virtual void init() override;

    virtual void play(std::string id, bool repeat) override;

    LoonLight() { }

    virtual void terminate() override;
private:
    static std::string BASE;
    std::map<std::string,std::string> references;

    void initIrr();
};


#endif //EMPATHY_LOONLIGHT_H
