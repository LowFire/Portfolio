#pragma once

#include <iostream>
#include <vector>
#include <string>

//Needed classes
#include "Init.h"
#include "Shader.h"
#include "Texture.h"
#include "Window.h"

class Graphical
{
public:
	Window win;
	Init init;
	//std::vector<Shader> shaders;
	//std::vector<Texture> textures;
};