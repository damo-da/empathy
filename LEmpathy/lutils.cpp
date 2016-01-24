#include "lempathy.hpp"

void LEmpathy::key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	cout<<"key call back received"<<endl;
	
	//LEmpathy is in the variable `instance`

	// When a user presses the escape key, we set the WindowShouldClose property to true,
	// closing the application
	
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(instance->window, GL_TRUE);

}