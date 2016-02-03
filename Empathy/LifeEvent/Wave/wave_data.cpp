#include <math.h>
#include "wave_data.hpp"


WaveData::WaveData(GLfloat radius, GLfloat centerX, GLfloat centerY) {
	this->radius = radius;
	this->centerX = centerX;
	this->centerY = centerY;
}

WaveData::WaveData( GLfloat radius, GLfloat centerX, GLfloat centerY, bool initGL) {
	this->radius = radius;
	this->centerX = centerX;
	this->centerY = centerY;

	if (initGL)initVertexObjects();
}

void WaveData::initVertexObjects() {
	// cout<<"initing vertex objects"<<endl;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
}

void WaveData::calculateGlVertices(GLfloat depth) {
	if (!(VAO && VBO))return;

	// cout << "Calculating vertices" << endl;
	vertices.clear();

	float diff = 0.01f;
	float cerv = 2 * M_PI * radius;


	for (float i = 0; i < cerv; i += diff) {
		float angle = 2 * M_PI * i / cerv;

		float x = radius * cos(angle) + centerX;
		float y = radius * sin(angle) + centerY;

		vertices.push_back(x);
		vertices.push_back(y);
		vertices.push_back(depth);
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
void WaveData::draw() {
	// Draw the circle
	glBindVertexArray(VAO);
	glDrawArrays(GL_LINE_LOOP, 0, vertices.size() / 3);
	glBindVertexArray(0);
	// cout<<"drawn "<<endl;
}
GLuint WaveData::getVAO() {
	return VAO;
}
GLuint WaveData::getVBO() {
	return VBO;
}
void WaveData::destroy() {
	// cout<<"destroyed"<<endl;
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);

}