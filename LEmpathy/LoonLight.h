//
// Created by damo on 1/29/16.
//

#ifndef EMPATHY_LOONLIGHT_H
#define EMPATHY_LOONLIGHT_H


#include "../Empathy/Implements/MoonLight.h"

class LoonLight : public MoonLight{

public:


    virtual void init() override;

    virtual void play(std::string id, bool repeat) override;

    LoonLight() { }
};


#endif //EMPATHY_LOONLIGHT_H
