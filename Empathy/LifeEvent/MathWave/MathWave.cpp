//
// Created by damo on 1/27/16.
//

#include <math.h>
#include "MathWave.h"

using namespace std;

void LifeEvent_MathWave::draw(GLuint shaderProgram) {
    LifeEvent::draw(shaderProgram);

    glUseProgram(shaderProgram);

    // cout<<"Drawing"<<endl;
    glLineWidth(getPencilSize());

    //set Vertex Color
    GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "vertexColor");
    glUniform4f(vertexColorLocation, color[0], color[1], color[2], color[3]);

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size() / 2);
    glBindVertexArray(0);

    glUseProgram(0);

}

void LifeEvent_MathWave::destroy() {
    LifeEvent::destroy();

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void LifeEvent_MathWave::init() {
    std::cout<<"init done"<<std::endl;
    LifeEvent::init();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    color = {1.0f, 1.0f, 1.0f, 1.0f};

    setOffsetX(0.0f);
    setOffsetY(0.0f);
    setZoomX(1.0f);
    setZoomY(1.0f);
    setLength(1.0f);
    setDiff(0.01f);
    setHead(-0.2f);
    setSpeed(0.1f);
    setHorizontal(true);
    setPencilSize(2.0f);

    startedDestroying=false;
}

void LifeEvent_MathWave::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    color = {r, g, b, a};
}


void LifeEvent_MathWave::passTime(GLfloat delTime) {
    LifeEvent::passTime(delTime);

    if (!(VAO && VBO))return;

    std::vector<GLfloat> vertices;

    for(float i=0;i<getLength();i+=getDiff()){
        GLfloat x=i + getHead() + getSpeed() * getTime();
        GLfloat y=getY(x);

        x += getOffsetX();
        y += getOffsetY();

        x *= getZoomX();
        y *= getZoomY();

        if(isHorizontal()){
            vertices.push_back(x);
            vertices.push_back(y);
        }else{
            vertices.push_back(y);
            vertices.push_back(x);
        }

    }

    render(vertices);
}


LifeEvent_MathWave::LifeEvent_MathWave(bool h):
        LifeEvent(),
        horizontal(h) {
    init();
};

LifeEvent_MathWave::LifeEvent_MathWave() {
    init();
}

void LifeEvent_MathWave::render(std::vector<GLfloat> &vertices) {

    this->vertices=vertices;

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), &vertices[0], GL_STREAM_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed,

    glBindVertexArray(0); // Unbind VAO
    // cout<<"calculated vertices"<<endl;
}