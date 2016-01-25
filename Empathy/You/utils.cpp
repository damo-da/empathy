#include "you.hpp"

int You::calcFPS(){
	float curTime=glfwGetTime();

	deltaTime=curTime-lastTime;

	lastTime=curTime;

	int FPS=1/deltaTime;
	cout<<"FPS "<<FPS<<endl;
	return FPS;
}