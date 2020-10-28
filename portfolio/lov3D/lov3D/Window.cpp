#include "Window.h"


void Window::setWindowHint(int setting, int hint)
{
	glfwWindowHint(setting, hint);
}


bool Window::formWindow()
{
	window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "ERROR: Failed to create window\n";
		glfwTerminate();
		return false;
	}
	else
	{
		glfwMakeContextCurrent(window);
		return true;
	}
}