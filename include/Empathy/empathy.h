//
// Created by damo on 2/20/16.
//

#ifndef EMPATHY_E_H
#define EMPATHY_E_H

#include "global.h"

/* The empathy namespace and classes header file.
 * This file contains the definition for all classes and namespaces used by the platform-independent Empathy.
 *
 * It is recommended that all files include this header file at the beginning.
 */
namespace empathy{

    /* Life Events run on the gamescreen to make it colorful and beautiful. */
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

    /* Brains gives logic to the program. They determine when and how a lifeEvent appears on the screen. */
    namespace brain{
        class Brain;

        class MusicalBrain;

        class JSONBrain;

        class DummyBrain;
    };

    /* It's amazing how audio sounds the best in moonlight. */
    namespace moonlight{
        class MoonLight;
        class BasicNote;
    };

    /* All mathematical stuffs will be placed here. And that's an order. */
    namespace pure_math{
        class Wave;
    }

    /* Used to communicate within the app.
     *
     * Uses over Radio frequency of frquency: 98.02 Mhz.
     * Just kidding! it communicates using emission and reception of events.
     * To either emit or receive an event, one must override the <Subscriber> class.
     * Also see: <Event> and <Subscriber>
     */
    namespace radio{
        class BroadcastStation;
        class Event;
        class Subscriber;
        class TimeBroadcaster;
    }

    /* Empathy Utilities. */
    namespace utils{

    };

    /* The main Empathy app. */
    class Empathy;

    /* You have all the brains. And the brains manipulate lifeEvents on You. */
    class You;
};



#ifndef EMPATHY_GLOBAL
#define EMPATHY_GLOBAL

#define EMPATHY_EVENT_INPUT_KEY_PRESS "EMPATHY_EVENT_INPUT_KEY_PRESS"
#define EMPATHY_EVENT_INPUT_KEY_RELEASE "EMPATHY_EVENT_INPUT_KEY_PRESS"
#define EMPATHY_EVENT_INPUT_KEY_REPEAT "EMPATHY_EVENT_INPUT_KEY_PRESS"

#define EMPATHY_EVENT_INPUT_KEY "EMPATHY_EVENT_INPUT_KEY"

#define EMPATHY_EVENT_INPUT_MOUSE_LEFT_KEY_PRESS "EMPATHY_EVENT_INPUT_MOUSE_LEFT_KEY_PRESS"
#define EMPATHY_EVENT_INPUT_MOUSE_RIGHT_KEY_PRESS "EMPATHY_EVENT_INPUT_MOUSE_RIGHT_KEY_PRESS"
#define EMPATHY_MOUSE_XPOS "EMPATHY_MOUSE_XPOS"
#define EMPATHY_MOUSE_YPOS "EMPATHY_MOUSE_YPOS"

#define EMPATHY_CREATE_EVENT "EMPATHY_CREATE_EVENT"
#endif

#endif //EMPATHY_E_H
