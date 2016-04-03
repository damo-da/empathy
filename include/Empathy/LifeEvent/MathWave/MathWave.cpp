//
// Created by damo on 1/27/16.
//

#include <math.h>
#include "MathWave.h"
#include "../../Shader/DefaultShader.h"

using namespace std;

void empathy::life_event::MathWave::draw() {
    empathy::shader::DefaultShader::use();

    // cout<<"Drawing"<<endl;
    glLineWidth(getPencilSize());

    //set Vertex Color
    empathy::shader::DefaultShader::setVertexColor(this);

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size() / 3);
    glBindVertexArray(0);

    glUseProgram(0);
}

void empathy::life_event::MathWave::onDestroy() {
    LifeEvent::onDestroy();

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void empathy::life_event::MathWave::onInit() {
    LifeEvent::onInit();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
}


empathy::life_event::MathWave::MathWave():
        LifeEvent(),
        Color(),
        offsetX(0.0f),
        offsetY(0.0f),
        zoomX(1.0f),
        zoomY(1.0f),
        length(1.0f),
        diff(0.003f),
        head(-0.0f),
        tail(0.9f),
        speed(0.15f),
        rotationAngle(0.0f),
        pencilSize(2.0f)
{

}

void empathy::life_event::MathWave::render(std::vector<GLfloat> &vertices) {

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


void empathy::life_event::MathWave::onRun(GLfloat delTime) {
    if(getTail() < getSpeed()*getTimeSinceRun()+getLength() + getHead()){
        doneRunning();
    }

    calcVertices();
}

void empathy::life_event::MathWave::onCreate(GLfloat delTime) {
    if(getLength() <= getTimeSinceCreate()*getSpeed()){
        doneCreating();
    }

    calcVertices();
}

void empathy::life_event::MathWave::onFinish(GLfloat delTime) {

    if(getHead() + getTimeSinceRun()*getSpeed()>getTail()){
        doneFinishing();
    }

    calcVertices();
}

void empathy::life_event::MathWave::calcVertices() {
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

GLfloat empathy::life_event::MathWave::getStartTheta() {
    if(isCreating())
        return getHead();
    else if(isRunning())
        return getHead()+ getSpeed() * getTimeSinceRun();
    else if(isFinishing())
        return getHead()+ getSpeed() * getTimeSinceRun();
    return 0;
}

GLfloat empathy::life_event::MathWave::getEndTheta() {

    if(isCreating())
        return getHead() + getSpeed() * getTimeSinceCreate();
    else if(isRunning())
        return getHead() + getSpeed() * getTimeSinceCreate();
    else if(isFinishing())
        return getTail();

    return 0;
}

GLfloat empathy::life_event::MathWave::getX(GLfloat theta) {
    return theta;
}

void empathy::life_event::MathWave::decodeJson(std::string key, cJSON *value) {
    LifeEvent::decodeJson(key, value);
    Color::decodeJson(key,value);

    if(key=="offsetX"){
        setOffsetX(value->valuedouble);
    }else if(key=="offsetY"){
        setOffsetY(value->valuedouble);
    }else if(key=="length"){
        setLength(value->valuedouble);
    }else if(key=="zoomX"){
        setZoomX(value->valuedouble);
    }else if(key=="zoomY"){
        setZoomY(value->valuedouble);
    }else if(key=="rendering_diff"){
        setDiff(value->valuedouble);
    }else if(key=="speed"){
        setSpeed(value->valuedouble);
    }else if(key=="rotationAngle"){
        setRotationAngle(value->valuedouble);
    }else if(key=="pencilSize"){
        setPencilSize(value->valuedouble);
    }else if(key=="head"){
        setHead(value->valuedouble);
    }else if(key=="tail"){
        setTail(value->valuedouble);
    }

}
