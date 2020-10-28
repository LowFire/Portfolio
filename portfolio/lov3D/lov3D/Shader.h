#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
private:
	std::string vertexPath;
	std::string fragmentPath;
	std::string name; //To help identify the shader
	int id;

	bool validate(); //Check if shader program is valid

public:
	Shader(std::string vertexPath, std::string fragmentPath, std::string name);

	int getID() const { return id; }
	void setID(int id) { this->id = id; }

	void use();
	void setInt(const std::string &name, const int aNumber);
	void setBool(const std::string &name, const bool aBool);
	void setFloat(const std::string &name, const float aFloat);
	void setMat4(const std::string &name, const glm::mat4 &aMatrix);
	void setVec3(const std::string &name, const glm::vec3 &aVec);
};