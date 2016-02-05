//
// Created by damo on 2/5/16.
//

#include "LifeEvent_CWave_data.h"
#include "../Shader.h"
using namespace std;

LifeEvent_CWave_data::LifeEvent_CWave_data(GLfloat cX, GLfloat cY):centerX(cX),centerY(cY) {

}


void LifeEvent_CWave_data::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    color = {r, g, b, a};
}

void LifeEvent_CWave_data::onInit() {
    LifeEvent::onInit();

    frequency=0.95f;
    waveLength = 0.1f;

    color = {1.0f, 1.0f, 1.0f, 1.0f};

    // cout<<"initing vertex objects"<<endl;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
}

void LifeEvent_CWave_data::onRun(GLfloat delTime) {
    // cout << "Calculating vertices" << endl;
    vertices.clear();


    radius = getTimeSinceRun() * getWaveSpeed();

    float diff = 0.01f;
    float cerv = 2 * M_PI * radius;


    for (float i = 0; i < cerv; i += diff) {
        float angle = 2 * M_PI * i / cerv;

        float x = radius * cos(angle) + centerX;
        float y = radius * sin(angle) + centerY;

        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(getDepth());
    }

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), &vertices[0], GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed,

    glBindVertexArray(0); // Unbind VAO
    // cout<<"calculated vertices"<<endl;
}

void LifeEvent_CWave_data::onDestroy() {
    LifeEvent::onDestroy();

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void LifeEvent_CWave_data::draw() {
    Shader::use();

    // cout<<"Drawing"<<endl;
    glLineWidth(2.5);

    Shader::setVertexColor(color);

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINE_LOOP, 0, vertices.size() / 3);
    glBindVertexArray(0);

    glUseProgram(0);
}
