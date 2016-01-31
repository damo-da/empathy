//
// Created by damo on 1/31/16.
//

#ifndef EMPATHY_SHADER_H
#define EMPATHY_SHADER_H


#include <GL/glew.h>
#include <iostream>
#include <vector>
class Shader {
public:
    static GLuint shaderProgram;
    static void init();

    static void use();

    static void setVertexColor(std::vector<GLfloat> color);
};


#endif //EMPATHY_SHADER_H
