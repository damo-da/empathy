/*
 * All the life events happen, and You are the one who makes them happen!
 * You handle all the events in life! 
 */

#ifndef EMPATHY_YOU
#define EMPATHY_YOU

#include "../empathy.h"
#include "../RadioStation/Subscriber.h"

#include <vector>
#include <GL/glew.h>
#include "../LifeEvent/Background/Background.h"

namespace empathy {
    class You : public radio::Subscriber {

        life_event::Background* background;
    public:
        /* The constructor. */
        You();

        /* Initialize You. And GL. */
        void init();

        /* Render all lifeEvents on the screen. */
        void blit();

        /* Add a lifeEvent to the queue. */
        void addLifeEvent(life_event::LifeEvent *);

        /* Remove a lifeEvent from the queue. */
        void removeLifeEvent(life_event::LifeEvent *);

        /* Clear the lifeEvents queue. */
        void clearLifeEvents();

        /* Calculate FPS. */
        int calcFPS(GLfloat curTime);

        /* Called from the Empathy app. This comes directly from the flavor in which Empathy runs on. */
        void setTime(GLfloat);

        /* Start a brain. */
        void addBrain(brain::Brain *);

        /* The Terminator kills you. o.o */
        void terminate();

        life_event::Background * getBackground(){return background;}

    private:
        /* FPS stuffs. */
        GLfloat lastTime, deltaTime;

        /* The lifeEvent list. These lifeEvents are currently being shown on gamescreen.*/
        std::vector<life_event::LifeEvent *> lifeEvents;

        /* THe brain list. THese brains are currently running. */
        std::vector<brain::Brain *> brains;

        /* pass a certain amount of time. */
        void passTime(GLfloat delTime);

    public:
        /* Return the lastinstance. */
        static You *getInstance() { return instance; }
    private:
        /* The last instance holder. */
        static You *instance;

    };
}
#endif