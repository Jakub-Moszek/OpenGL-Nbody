#include <GL/GLEW.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

#include "Default.h"

int main()
{
	GLFWwindow* window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, "NBody", NULL, NULL);
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HEIGHT, "NBody", NULL, NULL);
	if(!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	GLenum err = glewInit();
	if(err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	while (!glfwWindowShouldClose(window))
	{          
		
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}