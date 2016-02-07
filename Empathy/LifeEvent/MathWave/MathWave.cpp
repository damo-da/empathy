//
// Created by damo on 1/27/16.
//

#include <math.h>
#include "MathWave.h"
#include "../../Shader/DefaultShader.h"

using namespace std;

void LifeEvent_MathWave::draw() {
    DefaultShader::use();

    // cout<<"Drawing"<<endl;
    glLineWidth(getPencilSize());

    //set Vertex Color
    DefaultShader::setVertexColor(this);

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size() / 3);
    glBindVertexArray(0);

    glUseProgram(0);
}

void LifeEvent_MathWave::onDestroy() {
    LifeEvent::onDestroy();

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void LifeEvent_MathWave::onInit() {
    LifeEvent::onInit();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    setOffsetX(0.0f);
    setOffsetY(0.0f);

    setZoomX(1.0f);
    setZoomY(1.0f);

    setLength(1.0f);

    setDiff(0.003f);

    setHead(-0.0f);
    setTail(0.98f);

    setSpeed(0.15f);

    setRotationAngle(0.0f);

    setPencilSize(2.0f);
}


LifeEvent_MathWave::LifeEvent_MathWave():LifeEvent(),Color() {

}

void LifeEvent_MathWave::render(std::vector<GLfloat> &vertices) {

    this->vertices=vertices;

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), &vertices[0], GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed,

    glBindVertexArray(0); // Unbind VAO
    // cout<<"calculated vertices"<<endl;
}


void LifeEvent_MathWave::onRun(GLfloat delTime) {
    if(getTail() < getSpeed()*getTimeSinceRun()+getLength() + getHead()){
        doneRunning();
    }

    calcVertices();
}

void LifeEvent_MathWave::onCreate(GLfloat delTime) {
    if(getLength() <= getTimeSinceCreate()*getSpeed()){
        doneCreating();
    }

    calcVertices();
}

void LifeEvent_MathWave::onFinish(GLfloat delTime) {

    if(getHead() + getTimeSinceRun()*getSpeed()>getTail()){
        doneFinishing();
    }

    calcVertices();
}

void LifeEvent_MathWave::calcVertices() {
//    cout<<"calculating"<<endl;
    if (!(VAO && VBO))return;

    this->vertices.clear();

    std::vector<GLfloat> vertices;

    for(GLfloat i= getStartTheta(); i < getEndTheta(); i+=getDiff()){
        GLfloat x=getX(i);
        GLfloat y=getY(i);

        x += getOffsetX();
        y += getOffsetY();

        x *= getZoomX();
        y *= getZoomY();

        GLfloat outX=x*cos(rotationAngle)-y*sin(rotationAngle);
        GLfloat outY=x*sin(rotationAngle)+y*cos(rotationAngle);

        vertices.push_back(outX);
        vertices.push_back(outY);
        vertices.push_back(getDepth());
    }

    render(vertices);
}

GLfloat LifeEvent_MathWave::getStartTheta() {
    if(isCreating())
        return getHead();
    else if(isRunning())
        return getHead()+ getSpeed() * getTimeSinceRun();
    else if(isFinishing())
        return getHead()+ getSpeed() * getTimeSinceRun();
}

GLfloat LifeEvent_MathWave::getEndTheta() {

    if(isCreating())
        return getHead() + getSpeed() * getTimeSinceCreate();
    else if(isRunning())
        return getHead() + getSpeed() * getTimeSinceCreate();
    else if(isFinishing())
        return getTail();

}

GLfloat LifeEvent_MathWave::getX(GLfloat theta) {
    return theta;
}
