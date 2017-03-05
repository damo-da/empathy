//
// Created by geek on 4/6/16.
//

#ifndef DEMPATHY_LINEAR_LINEAR_LOONLIGHT_H
#define DEMPATHY_LINEAR_LINEAR_LOONLIGHT_H

#include "../empathy.h"
#include "../MoonLight/MoonLight.h"
#include <iostream>
#include <stack>

namespace empathy_linear {
    class Linear_MoonLight : public empathy::moonlight::MoonLight {

    private:
        std::stack<empathy::moonlight::BasicNote> musicalKeyboardEvents;
        std::stack<std::string> events;
    public:
        Linear_MoonLight();

        virtual void init() override;

        virtual void terminate() override;

        std::stack<empathy::moonlight::BasicNote> getMusicalKeyboardEvents();
        std::stack<std::string> getMusicalEvents();

    protected:
        virtual void playKeyboard(empathy::moonlight::BasicNote note) override;

        virtual void play(std::string id, bool repeat) override;
    };
}

#endif //DEMPATHY_LINEAR_LINEAR_LOONLIGHT_H
