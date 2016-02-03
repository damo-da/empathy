#ifndef EMPATHY_LIFE_EVENT_WAVE_DATA
#define EMPATHY_LIFE_EVENT_WAVE_DATA

#include "../../global.hpp"


#include <vector>
#include <GL/glew.h>

class WaveData{
public:

	GLfloat radius;
	GLfloat centerX;
	GLfloat centerY;
	GLuint VAO;
	GLuint VBO;
	GLfloat depth;

	std::vector<GLfloat> vertices;

	WaveData(GLfloat radius,GLfloat,GLfloat);
	WaveData(GLfloat radius,GLfloat,GLfloat,bool);
	void initVertexObjects();
	void calculateGlVertices();
	GLuint getVAO();
	GLuint getVBO();
	void destroy();
	void draw();


    GLfloat getDepth() const {
        return depth;
    }

    void setDepth(GLfloat depth) {
        WaveData::depth = depth;
    }

    GLfloat getRadius() const {
        return radius;
    }

    void setRadius(GLfloat radius) {
        WaveData::radius = radius;
    }

    GLfloat getCenterY() const {
        return centerY;
    }

    void setCenterY(GLfloat centerY) {
        WaveData::centerY = centerY;
    }

    GLfloat getCenterX() const {
        return centerX;
    }

    void setCenterX(GLfloat centerX) {
        WaveData::centerX = centerX;
    }
};


#endif