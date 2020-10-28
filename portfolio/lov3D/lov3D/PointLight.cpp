#include "PointLight.h"

PointLight::PointLight()
{
   position = glm::vec3(0.0f);

   constant = 1.0f;
   linear = 0.045f;
   quadratic = 0.0075f;

   ambient = glm::vec3(0.0f);
   diffuse = glm::vec3(1.0f);
   specular = glm::vec3(1.0f);
}

PointLight::PointLight(glm::vec3 position)
{
	this->position = position;

	constant = 1.0f;
	linear = 0.045f;
	quadratic = 0.0075f;

	ambient = glm::vec3(0.0f);
	diffuse = glm::vec3(1.0f);
	specular = glm::vec3(1.0f);
}

PointLight::PointLight(glm::vec3 position, glm::vec3 color)
{
   this->position = position;

   constant = 1.0f;
   linear = 0.045f;
   quadratic = 0.0075f;

   ambient = glm::vec3(0.0f);
   diffuse = color;
   specular = color;
}

PointLight::PointLight(PointLight &rhs)
{
   this->position = rhs.position;

   this->constant = rhs.constant;
   this->linear = rhs.linear;
   this->quadratic = rhs.quadratic;

   this->ambient = rhs.ambient;
   this->diffuse = rhs.diffuse;
   this->specular = rhs.specular;
}

PointLight& PointLight::operator=(PointLight &rhs)
{
   this->position = rhs.position;

   this->constant = rhs.constant;
   this->linear = rhs.linear;
   this->quadratic = rhs.quadratic;

   this->ambient = rhs.ambient;
   this->diffuse = rhs.diffuse;
   this->specular = rhs.specular;

   return *this;
}