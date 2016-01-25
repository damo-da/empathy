#ifndef EMPATHY_LIFE_EVENT_WAVE_DATA
#define EMPATHY_LIFE_EVENT_WAVE_DATA

#include "../../global.hpp"


#include <vector>

class WaveData{
public:
	GLfloat amplitude;
	GLfloat radius;
	GLfloat centerX;
	GLfloat centerY;
	GLuint VAO;
	GLuint VBO;
	std::vector<GLfloat> vertices;

	WaveData(GLfloat,GLfloat,GLfloat,GLfloat);
	WaveData(GLfloat,GLfloat,GLfloat,GLfloat,bool);
	void initVertexObjects();
	void calculateGlVertices();
	GLuint getVAO();
	GLuint getVBO();
	void destroy();
	void draw(GLuint);
};	


#endif