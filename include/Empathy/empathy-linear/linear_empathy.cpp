//
// Created by geek on 4/5/16.
//

#include <queue>
#include "linear_empathy.h"

using namespace std;

namespace empathy_linear{
    static GLfloat time;

    static Empathy_Linear* _instance;

    Empathy_Linear * getInstance();
    Linear_MoonLight * moonLight;

    class Empathy_Linear:public empathy::Empathy{

    protected:
        virtual GLfloat getTime() override {
            return time;
        }


    public:
        virtual void loop() override {
            empathy::Empathy::loop();
        }

        virtual bool shouldClose() override {
            return empathy::Empathy::shouldClose();
        }

        virtual void flush() override {
            empathy::Empathy::flush();
        }


        virtual void init() override {
            empathy_linear::moonLight=new Linear_MoonLight();
            setMoonLight(empathy_linear::moonLight);

            empathy::Empathy::init();

            setScreenSize(700,700);
        }

    public:
        virtual void run() override {

        }
    };

    bool shouldClose() {
        return getInstance()->shouldClose();
    }

    std::stack<empathy::moonlight::BasicNote> getMusicalKeyboardEvents() {
        return moonLight->getEvents();
    }

    void addDummyTouchBrain() {
        (new empathy::brain::DummyTouchBrain())->addTo(getInstance());
    }

    void init(){
        getInstance()->init();
    }

    void loop() {
        getInstance()->loop();
    }

    void flush() {
        getInstance()->flush();
    }

    void addJsonBrain(std::string name) {
        empathy::brain::JSONBrain * brain=new empathy::brain::JSONBrain(name);
        brain->addTo(getInstance());
    }

    Empathy_Linear * getInstance(){
        if(_instance== nullptr)
            _instance=new Empathy_Linear();

        return _instance;
    }


    void setTime(GLfloat time) {
        empathy_linear::time=time;
    }

    void makeReadyToClose() {
        getInstance()->makeReadyToClose();
    }


}
