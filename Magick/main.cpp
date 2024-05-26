#include "src/Shader.h"
#include "src/Buffer.h"
#include "src/Random.h"
#include "src/Game.h"

#include <GLFW/glfw3.h>

const int WIDTH = 600;
const int HEIGHT = 400;

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
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Magick", nullptr, nullptr);
	if (!window) { std::cerr << "Failed to create GLFW window" << std::endl;  glfwTerminate(); return -2; }

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window,
		[](GLFWwindow* window, int width, int height) 
			{ glViewport(0, 0, width, height); }
	);
	glfwSetKeyCallback(window, key_callback);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) { std::cerr << "Failed to init glad" << std::endl; return -2; }

	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	std::vector<float> vertices = {
		0.5f,  0.5f,	1.0f, 1.0f,
    	0.5f, -0.5f,	1.0f, 0.0f,
       -0.5f, -0.5f,	0.0f, 0.0f,
       -0.5f,  0.5f,	0.0f, 1.0f
	};
	std::vector<GLuint> indices = {
		0, 1, 3,
		1, 2, 3
	};

	Buffer VBO(GL_ARRAY_BUFFER);
	Buffer EBO(GL_ELEMENT_ARRAY_BUFFER);
	VBO.setData(vertices, GL_STATIC_DRAW);
	EBO.setData(indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	Game Magick(WIDTH, HEIGHT);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5, 0.5, 0.5, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		VBO.bind();
		EBO.bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		VBO.unbind();
		EBO.unbind();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}