#include "DeltaTime.h"

void DeltaTime::update()
{
	currentFrame = glfwGetTime();
	time = currentFrame - lastFrame;
	lastFrame = currentFrame;
}