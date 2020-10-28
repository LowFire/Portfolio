#pragma once

#include <iostream>
#include <string>
#include "glad/glad.h"

class Texture
{
private:
	std::string path;
	int width;
	int height;
	int channels;
	int target;
	int unitLocation; //refers to which texture unit the texture is in
	unsigned int id;

public:
	Texture(std::string path, int target, int unitLocation);
	int getID() const  { return id; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }
	int getChannels() const { return channels; }
	void changeTarget(int target) { this->target = target; }

	void loadImg();
	void use();

};