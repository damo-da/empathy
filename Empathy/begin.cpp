#include "empathy.hpp"

void Empathy::begin() {
	cout<<"empathy begin"<<endl;

	while (! glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		you->passTime(1);
		
		you->blit();

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

	you->clearEvents();

	flush();
}