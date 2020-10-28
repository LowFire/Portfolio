#include "Camera.h"

Camera::Camera(float aspectRatio)
{
	speed = 10.0f;
	deltaSpeed = speed;
	pitch = 0;
	yaw = 0;
	fov = 45.0f;
	this->aspectRatio = aspectRatio;
	cameraPos = { 0.0f, 0.0f, 3.0f };
	cameraFront = { 0.0f, 0.0f, -1.0f };
	cameraUp = { 0.0f, 1.0f, 0.0f };
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	projection = glm::perspective(glm::radians(fov), aspectRatio, 0.1f, 100.0f);
}

void Camera::moveForward()
{
	cameraPos += cameraFront * deltaSpeed;
	update();
}


void Camera::moveBackward()
{
	cameraPos -= cameraFront * deltaSpeed;
	update();
}


void Camera::moveRight()
{
	cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * deltaSpeed;
	update();
}


void Camera::moveLeft()
{
	cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * deltaSpeed;
	update();
}

void Camera::update()
{
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	//projection = glm::perspective(glm::radians(fov), aspectRatio, 0.1f, 100.0f);
}