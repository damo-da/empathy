#ifndef DEMPATHY_LINEAR_EMPATHY_LINEAR_H
#define DEMPATHY_LINEAR_EMPATHY_LINEAR_H

#include "../Utils/string_utils.h"
#include "../Empathy/Empathy.h"
#include "../Brain/JSONBrain/JSONBrain.h"
#include "../Brain/DummyTouchBrain/DummyTouchBrain.h"
#include "../Brain/EmotionBrain/EmotionBrain.h"

#include "linear_moonlight.h"

namespace empathy_linear{
    bool shouldClose();

    void flush();

    std::stack<empathy::moonlight::BasicNote> getMusicalKeyboardEvents();

    void loop();

    void setTime(GLfloat time);

    class Empathy_Linear;

    void init();

    void addJsonBrain(std::string name);

    void addEmotionBrain();

    void addDummyTouchBrain();

    void makeReadyToClose();

    void setScreenSize(GLint size);
    void setScreenMargins(GLint x,GLint y);
}


#endif //DEMPATHY_LINEAR_EMPATHY_LINEAR_H
