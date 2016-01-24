#include "empathy.hpp"

void Empathy::flush(){
	cout<<"Flush done"<<endl;
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
}