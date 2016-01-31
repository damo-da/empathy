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
	std::vector<GLfloat> vertices;

	WaveData(GLfloat radius,GLfloat,GLfloat);
	WaveData(GLfloat radius,GLfloat,GLfloat,bool);
	void initVertexObjects();
	void calculateGlVertices();
	GLuint getVAO();
	GLuint getVBO();
	void destroy();
	void draw();
};	


#endif