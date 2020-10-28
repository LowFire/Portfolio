#pragma once

#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>

class Init
{
public:
	Init() {}

	bool GLFW();
	bool GLAD();
	void version(int verMinor, int verMajor);
	void profile(int profile);
};