//
// Created by damo on 1/27/16.
//

#include <math.h>
#include "LifeEvent_SineWave.h"

void LifeEvent_SineWave::draw(GLuint shaderProgram) {
    LifeEvent::draw(shaderProgram);

    glUseProgram(shaderProgram);

    // cout<<"Drawing"<<endl;
    glLineWidth(2.5);

    //set Vertex Color
    GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "vertexColor");
    glUniform4f(vertexColorLocation, color[0], color[1], color[2], color[3]);

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_LOOP, 0, vertices.size() / 2);
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
}
void LifeEvent_SineWave::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    color = {r, g, b, a};
}

void LifeEvent_SineWave::passTime(GLfloat lfloat) {
//    std::cout<<"passTime done"<<std::endl;
    LifeEvent::passTime(lfloat);

    float radius=0.3f;

    if (!(VAO && VBO))return;

    // cout << "Calculating vertices" << endl;
    vertices.clear();

    float diff = 0.01f;
    float cerv = 2 * M_PI * radius;


    for (float i = 0; i < cerv; i += diff) {
        float angle = 2 * M_PI * i / cerv;

        float x = radius * cos(angle) ;
        float y = radius * sin(angle) ;

        vertices.push_back(x);
        vertices.push_back(y);
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


LifeEvent_SineWave::LifeEvent_SineWave(GLfloat length,GLfloat baseValue,GLfloat amplitude,GLfloat speed,bool horizontal):
        LifeEvent(),
        length(length),
        baseValue(baseValue),
        amplitude(amplitude),
        speed(speed),
        horizontal(horizontal) {
    init();
};

LifeEvent_SineWave::LifeEvent_SineWave(GLfloat length, GLfloat baseValue, GLfloat amplitude,GLfloat speed):
        LifeEvent(),
        length(length),
        speed(speed),
        baseValue(baseValue),
        amplitude(amplitude),
        horizontal(true) {
    init();
}

GLfloat LifeEvent_SineWave::diff=0.01f;