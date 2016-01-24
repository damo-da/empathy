#include "../life_event.hpp"

#ifndef LIFE_EVENT_WAVE
#define LIFE_EVENT_WAVE

class LifeEvent_Wave: public LifeEvent{
public:
	float radius;
	float width;
	const float diff=0.1f;

	GLfloat centerX;
	GLfloat centerY;


	void init();

	GLuint VBO,VAO;

	void draw(GLuint);

	void destroy();

	std::vector<GLfloat> vertices;

	LifeEvent_Wave(int,std::string);

	void setCenter(GLfloat x,GLfloat y){centerX=x;y=centerY;}

	LifeEvent_Wave(int,std::string,GLfloat,GLfloat);
private:
	
};

#endif