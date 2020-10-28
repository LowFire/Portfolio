#include "Texture.h"
#include <stb_image.h>

Texture::Texture(std::string path, int target, int unitLocation) : path(path), target(target), unitLocation(unitLocation)
{
	glGenTextures(1, &id);
	glActiveTexture(unitLocation);
	glBindTexture(target, id);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	loadImg();
}

void Texture::loadImg()
{
	unsigned char * data = stbi_load(path.c_str(), &width, &height, &channels, 0);
	if (data)
	{
		switch (channels)
		{
		case 3:
			glTexImage2D(target, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			break;
		case 4:
			glTexImage2D(target, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			break;
		}
		glGenerateMipmap(target);
	}
	else
		std::cout << "ERROR: Failed to load texture: " << path << '\n';
	stbi_image_free(data);
}

void Texture::use()
{
	glActiveTexture(unitLocation);
	glBindTexture(target, id);
}