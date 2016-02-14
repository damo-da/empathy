//
// Created by damo on 2/14/16.
//

#ifndef EMPATHY_MUSICALBRAIN_H
#define EMPATHY_MUSICALBRAIN_H


#include "../Brain.h"

class MusicalBrain : public Brain{

public:
    MusicalBrain();

protected:
    virtual void runLineNumber(int number, int caller) override;

public:
    GLfloat getFrequency() const {
        return frequency;
    }

    void setFrequency(GLfloat frequency) {
        MusicalBrain::frequency = frequency;
    }

    void setMusic(std::string);
private:
    GLfloat frequency;

    std::vector<std::vector<std::string>> sequence;
};


#endif //EMPATHY_MUSICALBRAIN_H
