/*
 * All the life events happen, and You are the one who makes them happen!
 * You handle all the events in life! 
 */

#ifndef EMPATHY_YOU
#define EMPATHY_YOU


#include "../global.h"
#include "../e.h"

#include <vector>
namespace empathy {
    class You : public empathy::radio::Subscriber {

    public:
        std::vector<empathy::life_event::LifeEvent *> lifeEvents;

        You();

        void init();

        void blit();

        void addEvent(empathy::life_event::LifeEvent *);

        void removeEvent(empathy::life_event::LifeEvent *);

        void clearEvents();

        long curTime;
        float lastTime, deltaTime;

        int calcFPS(GLfloat curTime);

        void passTime(GLfloat);

        void setTime(GLfloat);

        virtual void onReceiveEvent(empathy::radio::Event &) override;

        std::vector<empathy::brain::Brain *> brains;

        void addBrain(empathy::brain::Brain *);

        void terminate();

    public:
        static You *getInstance() { return instance; }

    private:
        static You *instance;
    };
}
#endif