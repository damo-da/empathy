#include "wave.hpp"
#include <iostream>
void LifeEvent_Wave::init(){
	cout<<"INIT"<<endl;
	float radius=0.2f;
	float cerv=2 * M_PI*radius;
	float diff=0.01f;

	
	for(float i=0;i < cerv; i+=diff){
		float angle=2 * M_PI * i/cerv;

		float x=radius * cos(angle) + centerX;
		float y=radius * sin(angle) + centerY;
		
		vertices.push_back(x);
		vertices.push_back(y);
	}
	

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(GLfloat), &vertices[0], GL_STREAM_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed,

	glBindVertexArray(0); // Unbind VAO 
}

void LifeEvent_Wave::destroy(){
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void LifeEvent_Wave::draw(GLuint shaderProgram){
	// cout<<"Drawing inherited"<<endl;

	GLfloat timeValue = glfwGetTime();
	GLfloat greenValue = (sin(timeValue) / 2) + 0.5;
	// cout<<timeValue<<" is curTIme"<<endl;
	glUseProgram(shaderProgram);

	//set Vertex Color
	GLint vertexColorLocation = glGetUniformLocation(shaderProgram, "vertexColor");
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

	// Draw the triangle
	glBindVertexArray(VAO);
	glDrawArrays(GL_LINE_LOOP, 0, vertices.size()/2);
	glBindVertexArray(0);

	glUseProgram(0);

	glLineWidth(2.5);
}


LifeEvent_Wave::LifeEvent_Wave(int i,std::string c):LifeEvent(i,c){
	radius=0.8f;
	init();
}

LifeEvent_Wave::LifeEvent_Wave(int i,std::string c,GLfloat cX,GLfloat cY):LifeEvent(i,c){
	radius=0.8f;

	centerX=cX;
	centerY=cY;
	
	init();
}