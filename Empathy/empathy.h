//
// Created by damo on 2/20/16.
//

#ifndef EMPATHY_E_H
#define EMPATHY_E_H


namespace empathy{
    namespace life_event{
        class LifeEvent;
        class Collection;

        class CWave;
        class CWave_data;

        class FadeInOut;

        class MathWave;
        class MathWave_Line;
        class MathWave_Para_Circle;
        class MathWave_Sinc;
        class MathWave_Sine;
    }

    namespace brain{
        class Brain;

        class MusicalBrain;

        class JSONBrain;

        class DummyBrain;
    };
    namespace moonlight{
        class MoonLight;
    };

    namespace pure_math{
        class Wave;
    }

    namespace radio{
        class BroadcastStation;
        class Event;
        class Subscriber;
        class TimeBroadcaster;
    }

    namespace utils{

    };

    class Empathy;
    class You;
};



#ifndef EMPATHY_GLOBAL
#define EMPATHY_GLOBAL

#define EMPATHY_EVENT_INPUT_KEY_PRESS "EMPATHY_EVENT_INPUT_KEY_PRESS"
#define EMPATHY_EVENT_INPUT_KEY_RELEASE "EMPATHY_EVENT_INPUT_KEY_PRESS"
#define EMPATHY_EVENT_INPUT_KEY_REPEAT "EMPATHY_EVENT_INPUT_KEY_PRESS"

#define EMPATHY_EVENT_INPUT_KEY "EMPATHY_EVENT_INPUT_KEY"

#define EMPATHY_CREATE_EVENT "EMPATHY_CREATE_EVENT"
#endif

#endif //EMPATHY_E_H
