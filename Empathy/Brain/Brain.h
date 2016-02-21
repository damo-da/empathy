#ifndef EMPATHY_BRAIN_H
#define EMPATHY_BRAIN_H

#define EMPATHY_EVENT_BRAIN_LINE_NUMBER "EMPATHY_EVENT_BRAIN_LINE_NUMBER"
#define EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER "EMPATHY_EVENT_BRAIN_CALLER_LINE_NUMBER"

#include "../empathy.h"
#include "../RadioStation/Subscriber.h"
#include "../LifeEvent/LifeEvent.h"

namespace empathy {
    namespace brain {

        /* Brain: the controller of lifevents.
         *
         * Consider them the computer which take time as input and give the output on the screen.
         *
         * Here's the deal: You want to build an amazing LifeEvent and also need dynamic control?
         * Well,you might need to extend this class, or send JSON to JSONBrain file.
         */
        class Brain : public empathy::radio::Subscriber {

        public:
            /* @inherit */
            virtual void onReceiveEvent(empathy::radio::Event &event) override;

            /* Constructor */
            Brain();

            /* Start running lines on this <Brain> usually called by the <You> class */
            void run();


            /* Add brain to an Empathy app.
             *
             * Sometimes a brain needs to dynamically do stuffs before adding itself to the app.
             * That's where addTo(Empathy) comes handy in.
             *
             * @binder the <Empathy> binder
             */
            virtual void addTo(empathy::Empathy *binder);


            /*
             * A basic override function created for handling brain termination due to program abort.
             *
             * Remember to call superclass while overriding.
             */
            virtual void terminate();

        public:
            /* How late the `begin` action should be called. */
            GLfloat getDelay() const {
                return delay;
            }

            /* How late the `begin` action should be called. */
            void setDelay(GLfloat delay) {
                this->delay = delay;
            }
        private:
            /* How late the `begin` action should be called. */
            GLfloat delay;

        protected:

            /* The logic provider.
             *
             * Any extension of Brain class must override this function. What it does is receive instructions.
             * For example, when the program begins, lineID is "begin" and when you need to play a music,
             * it will be something like "playBeethoven". Your choice.
             *
             * @lineID the identification of the line to be run.
             * @callerID the identification of the caller line number.
             *
             * Note that cross-brain communication is not supported.
             */
            virtual void runLineNumber(std::string lineID, std::string callerID) = 0;

            /* Activate timeout for a certain line.*/
            void activateTimeoutForNextLine(std::string lineID, GLfloat afterTime);

            /* Activate timeout for a certain line.*/
            void activateTimeoutForNextLine(std::string lineID, GLfloat afterTime, std::string callerLineID);

            /* Add life event to the current gamescreen.
             *
             * @event the event to be added.
             * */
            void addLifeEvent(empathy::life_event::LifeEvent *event);

        };
    }
}

#endif //EMPATHY_BRAIN_H
