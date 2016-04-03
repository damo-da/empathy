//
// Created by damo on 2/5/16.
//

#include "CWave_data.h"
#include "../../Shader/DefaultShader.h"

using namespace std;

empathy::life_event::CWave_data::CWave_data()
        :LifeEvent(),
         Color(),
         Wave()
{

}

void empathy::life_event::CWave_data::onInit() {
    LifeEvent::onInit();

    // cout<<"initing vertex objects"<<endl;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
}

void empathy::life_event::CWave_data::onRun(GLfloat delTime) {
    // cout << "Calculating vertices" << endl;
    vertices.clear();

    pure_math::Wave::setTime(getTimeSinceCreate());

    GLfloat radius = getTimeSinceRun() * getWaveSpeed();

    if(radius> EMPATHY_CWAVE_MAXIMUM_DISTANCE){
        doneRunning();
        return;
    }
    float diff = 0.01f;
    float cerv = 2 * M_PI * radius;

    setA(getAmplitudeAt(radius));

    for (float i = 0; i < cerv; i += diff) {
        float angle = 2 * M_PI * i / cerv;

        float x = radius * cos(angle) + getCenterX();
        float y = radius * sin(angle) + getCenterY();

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

void empathy::life_event::CWave_data::onDestroy() {
    LifeEvent::onDestroy();

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);
}

void empathy::life_event::CWave_data::draw() {
    empathy::shader::DefaultShader::use();

    // cout<<"Drawing"<<endl;
    glLineWidth(2.5);

    empathy::shader::DefaultShader::setVertexColor(this);

    glBindVertexArray(VAO);

    glDrawArrays(GL_LINE_LOOP, 0, vertices.size() / 3);
    glBindVertexArray(0);

    glUseProgram(0);
}

void empathy::life_event::CWave_data::decodeJson(std::string key, cJSON *value) {
    LifeEvent::decodeJson(key, value);
    Color::decodeJson(key,value);
    pure_math::Wave::decodeJson(key,value);
}
