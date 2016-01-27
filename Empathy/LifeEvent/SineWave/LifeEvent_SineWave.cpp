//
// Created by damo on 1/27/16.
//

#include <math.h>
#include "LifeEvent_SineWave.h"

using namespace std;

void LifeEvent_SineWave::draw(GLuint shaderProgram) {
    LifeEvent::draw(shaderProgram);

    glUseProgram(shaderProgram);

    // cout<<"Drawing"<<endl;
    glLineWidth(2.5f);

    //set Vertex Color
    GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "vertexColor");
    glUniform4f(vertexColorLocation, color[0], color[1], color[2], color[3]);

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_STRIP, 0, vertices.size() / 2);
    glBindVertexArray(0);

    glUseProgram(0);

}

void LifeEvent_SineWave::destroy() {
    std::cout<<"destruction done"<<std::endl;
    LifeEvent::destroy();

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void LifeEvent_SineWave::init() {
    std::cout<<"init done"<<std::endl;
    LifeEvent::init();

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    color = {1.0f, 1.0f, 1.0f, 1.0f};

    head=0.0f;
    period=8.0f;

    startedDestroying=false;
}

void LifeEvent_SineWave::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    color = {r, g, b, a};
}

void LifeEvent_SineWave::passTime(GLfloat lfloat) {
    LifeEvent::passTime(lfloat);

    if (!(VAO && VBO))return;

    vertices.clear();

    for(float i=0;i<getLength();i+=diff){
        GLfloat x=i + head;
        x += speed*getTime();
        GLfloat y=sin(x*period*2*M_PI)*amplitude;

        vertices.push_back(x);
        vertices.push_back(y);
    }

    //events handler
    if(head + getLength()+speed*getTime()>1.0f){

        if(!startedDestroying){
            Event e=Event(EMPATHY_LIFE_EVENT_SINE_WAVE_STARTED_DESTROYING);
            emit(e);

            startedDestroying=true;
        }else{
            if(head+speed*getTime()>1.0f){
                Event e=Event(EMPATHY_LIFE_EVENT_SINE_WAVE_DESTROYED);
                emit(e);

                setShouldDestroy(true);
            }
        }

    }

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), &vertices[0], GL_STREAM_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed,

    glBindVertexArray(0); // Unbind VAO
    // cout<<"calculated vertices"<<endl;
}


LifeEvent_SineWave::LifeEvent_SineWave(GLfloat l,GLfloat b,GLfloat a,GLfloat s,bool h):
        LifeEvent(),
        length(l),
        baseValue(b),
        amplitude(a),
        speed(s),
        horizontal(h) {
    init();
};

LifeEvent_SineWave::LifeEvent_SineWave(GLfloat l, GLfloat b, GLfloat a,GLfloat s):
        LifeEvent(),
        length(l),
        baseValue(b),
        amplitude(a),
        speed(s),
        horizontal(true) {


    init();
}

GLfloat LifeEvent_SineWave::diff=0.003f;

LifeEvent_SineWave::LifeEvent_SineWave() {
    init();
}
