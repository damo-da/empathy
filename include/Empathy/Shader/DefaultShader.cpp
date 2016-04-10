//
// Created by damo on 1/31/16.
//

#include "DefaultShader.h"
#include "shader_utils.h"
#include "../empathy.h"
using namespace std;

void empathy::shader::DefaultShader::init() {
    if(!initialized){
        shaderProgram=create_program(getAssetPath("shaders/default.v.glsl"),getAssetPath("shaders/default.f.glsl"));


        initialized=true;

        //run the assessment if not ran already
        setMarginTop(marginTop);
        setMarginLeft(marginLeft);
    }


}

void empathy::shader::DefaultShader::use() {
    glUseProgram(shaderProgram);
}


GLuint empathy::shader::DefaultShader::shaderProgram=0;
GLfloat empathy::shader::DefaultShader::marginTop=0;
GLfloat empathy::shader::DefaultShader::marginLeft=0;
bool empathy::shader::DefaultShader::initialized=false;

void empathy::shader::DefaultShader::setVertexColor(Color * color) {
    GLint vertexColorLocation = glGetUniformLocation(DefaultShader::shaderProgram, "vertexColor");
    glUniform4f(vertexColorLocation, color->getR(),color->getG(),color->getB(),color->getA());
}

void empathy::shader::DefaultShader::setMarginTop(GLfloat marginTop) {
    DefaultShader::marginTop = marginTop;

    if(initialized){

        cout<<"TOP IS "<<marginTop<<endl;

        GLint location = glGetUniformLocation(DefaultShader::shaderProgram, "marginTop");
        glUniform1f(location, marginTop);
    }
}

void empathy::shader::DefaultShader::setMarginLeft(GLfloat marginLeft) {
    DefaultShader::marginLeft = marginLeft;

    if(initialized){

        cout<<"LEFT IS "<<marginLeft<<endl;

        GLint location = glGetUniformLocation(DefaultShader::shaderProgram, "marginLeft");
        glUniform1f(location, marginLeft);
    }
}