#pragma once
#include <iostream>
#include <glm/glm.hpp>

class PointLight
{
private:
   glm::vec3 position;

   float constant;
   float linear;
   float quadratic;

   glm::vec3 ambient;
   glm::vec3 diffuse;
   glm::vec3 specular;
public:
   PointLight();
	PointLight(glm::vec3 position);
   PointLight(glm::vec3 position, glm::vec3 color);
   PointLight(PointLight &rhs);

   PointLight& operator=(PointLight &rhs);

   //getters and setters
   glm::vec3 getPos() const { return position; }
   float getConstant() const { return constant; }
   float getLinear() const { return linear; }
   float getQuadratic() const { return quadratic; }
   glm::vec3 getAmbient() const { return ambient; }
   glm::vec3 getDiffuse() const { return diffuse; }
   glm::vec3 getSpecular() const { return specular; }
};