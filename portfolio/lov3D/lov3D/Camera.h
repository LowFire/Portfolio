#pragma once

#include <iostream>

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "DeltaTime.h"

class Camera
{
private:
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::mat4 view;
	glm::mat4 projection;

	float aspectRatio;
	float fov;
	float speed;
	float deltaSpeed;

	float pitch;
	float yaw;

public:
	//Constructors
	Camera(float aspectRatio);

	//getters and setters
	glm::vec3 getPos() const { return cameraPos; }
	void setPos(glm::vec3 pos) { cameraPos = pos; }
	glm::vec3 getFront() const { return cameraFront; }
	void setFront(glm::vec3 front) { cameraFront = front; }
	glm::vec3 getUp() const { return cameraUp; }
	void setUp(glm::vec3 up) { cameraUp = up; }
	glm::mat4 getView() const { return view; }
	void setView(glm::mat4 view) { this->view = view; }
	glm::mat4 getProjection() const { return projection; }
	void setProjection(glm::mat4 projection) { this->projection = projection; }
	float getSpeed() const { return speed; }
	void setSpeed(float speed) { this->speed = speed; }
	float getDeltaSpeed() const { return deltaSpeed; }
	void setDeltaSpeed(float deltaSpeed) { this->deltaSpeed = deltaSpeed; }
	float getFov() const { return fov; }
	void setFov(float fov) { this->fov = fov; }

	//Movement methods
	void moveForward();
	void moveBackward();
	void moveRight();
	void moveLeft();

	//update
	void update();
};