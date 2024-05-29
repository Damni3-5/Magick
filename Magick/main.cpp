
#include "src/Game.h"


const int WIDTH = 600;
const int HEIGHT = 400;

Game Magick(WIDTH, HEIGHT);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			Magick.Keys[key] = true;
		else if (action == GLFW_RELEASE)
			Magick.Keys[key] = false;
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

	Magick.init();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.5, 0.5, 0.5, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		Magick.input(1);
		Magick.update(1);
		Magick.render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}