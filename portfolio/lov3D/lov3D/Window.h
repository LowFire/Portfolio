#pragma once

#include <iostream>
#include <string>
#include <glfw/glfw3.h>

class Window
{
private:
	unsigned int width;
	unsigned int height;
	std::string name;
	GLFWwindow * window; //Pointer to our window in OpenGL

public:
	//Constructors
	Window() : width(680), height(420), name("Untitled")
	{}

	//getters & setters
	int getWidth() const { return width; }
	void setWidth(unsigned int width) { this->width = width; }
	int getHeight() const { return height; }
	void setHeight(unsigned int height) { this->height = height; }
	std::string getName() const { return name; }
	void setName(std::string name) { this->name = name; }
	GLFWwindow * getWindow() const { return window; }

	void setWindowHint(int setting, int hint);
	bool formWindow();
};