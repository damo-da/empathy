#ifndef DEMPATHY_LINEAR_EMPATHY_LINEAR_H
#define DEMPATHY_LINEAR_EMPATHY_LINEAR_H

#include <Empathy/Utils/string_utils.h>
#include <Empathy/Empathy/Empathy.h>
#include "Empathy/Brain/JSONBrain/JSONBrain.h"
#include "Empathy/Brain/DummyTouchBrain/DummyTouchBrain.h"
#include <GLFW/glfw3.h>
#include "Linear_MoonLight.h"

namespace empathy_linear{
    bool shouldClose();

    void flush();

    std::stack<PlayableItem> getAudioEvents();

    void loop();

    void setTime(GLfloat time);

    class Empathy_Linear;

    void init();

    void addJsonBrain(std::string name);

    void addDummyTouchBrain();

    void makeReadyToClose();

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static void mouse_input_callback(GLFWwindow* window, int button, int action, int mods);
    static void mouse_position_callback(GLFWwindow* window,double xpos,double ypos);

}


#endif //DEMPATHY_LINEAR_EMPATHY_LINEAR_H
