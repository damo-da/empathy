//
// Created by geek on 4/6/16.
//

#ifndef DEMPATHY_LINEAR_LINEAR_LOONLIGHT_H
#define DEMPATHY_LINEAR_LINEAR_LOONLIGHT_H

#include <Empathy/empathy.h>
#include <Empathy/MoonLight/MoonLight.h>
#include <iostream>
#include <stack>


struct PlayableItem{
public:
    std::string fileName;
    bool repeat;

    PlayableItem(std::string fileName, bool repeat);
};

class Linear_MoonLight : public empathy::moonlight::MoonLight{

private:
    std::stack<PlayableItem> events;
public:
    Linear_MoonLight();

    virtual void init() override;

    virtual void terminate() override;

    std::stack<PlayableItem> getEvents();

protected:
    virtual void playKeyboard(std::string key) override;

    virtual void play(std::string id, bool repeat) override;
};


#endif //DEMPATHY_LINEAR_LINEAR_LOONLIGHT_H
