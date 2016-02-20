//
// Created by damo on 1/31/16.
//

#include "DefaultShader.h"
#include "shader_utils.h"
#include <iostream>
using namespace std;

void empathy::shader::DefaultShader::init() {
    shaderProgram=create_program("assets/shaders/default.v.glsl","assets/shaders/default.f.glsl");
}


void empathy::shader::DefaultShader::use() {
    glUseProgram(shaderProgram);
}


GLuint empathy::shader::DefaultShader::shaderProgram=0;

void empathy::shader::DefaultShader::setVertexColor(Color * color) {
    GLint vertexColorLocation = glGetUniformLocation(DefaultShader::shaderProgram, "vertexColor");
    glUniform4f(vertexColorLocation, color->getR(),color->getG(),color->getB(),color->getA());
}
