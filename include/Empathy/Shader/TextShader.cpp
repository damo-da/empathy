//
// Created by damo on 1/31/16.
//

#include "TextShader.h"
#include "shader_utils.h"
using namespace std;

void empathy::shader::TextShader::init() {
    shaderProgram=create_program(getAssetPath("shaders/text.v.glsl"),getAssetPath("shaders/text.f.glsl"));
    cout<<"Shader iss "<<shaderProgram<<endl;

}

void empathy::shader::TextShader::use() {
    glUseProgram(shaderProgram);
}


GLuint empathy::shader::TextShader::shaderProgram=0;


void empathy::shader::TextShader::flush() {
    glDeleteProgram(shaderProgram);
}

void empathy::shader::TextShader::setTextColor(Color *color) {
    GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "textColor");
    glUniform3f(vertexColorLocation, color->getR(),color->getG(),color->getB());

    glActiveTexture(GL_TEXTURE0);
}


