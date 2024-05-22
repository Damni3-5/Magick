#include <iostream>
#include "src/include.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
	glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (key >= 0 && key < 1024)
	{
		/*if (action == GLFW_PRESS)
			Cube.Keys[key] = true;
		else if (action == GLFW_RELEASE)
			Cube.Keys[key] = false;*/
	}
}

int main()
{
	if (!glfwInit()) { std::cerr << "Failed to init GLFW" << std::endl; return -2; }
	GLFWwindow* window = glfwCreateWindow(640, 480, "Magick", nullptr, nullptr);
	if (!window) { std::cerr << "Failed to create GLFW window" << std::endl;  glfwTerminate(); return -1; }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, key_callback);
	

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5, 0.5, 0.5, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}