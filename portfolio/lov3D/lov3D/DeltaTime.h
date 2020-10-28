#pragma once

#include <glfw/glfw3.h>

class DeltaTime
{
private:
	float time;
	float lastFrame;
	float currentFrame;

public:
	DeltaTime() : time(0.0f), lastFrame(0.0f), currentFrame(0.0f)
	{}

	//getters and setters
	float getTime() const { return time; }
	void setTime(float time) { this->time = time; }
	float getLastFrame() const { return lastFrame; }
	void setLastFrame(float time) { lastFrame = time; }
	float getCurrentFrame() const { return currentFrame; }
	void setCurrentFrame(float time) { currentFrame = time; }

	void update();
};