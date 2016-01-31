//
// Created by damo on 1/31/16.
//

#ifndef EMPATHY_SHADER_H
#define EMPATHY_SHADER_H


#include <GL/glew.h>

class Shader {
    static void use();
public:
    static GLuint shaderProgram;
    static void init();
};


#endif //EMPATHY_SHADER_H
