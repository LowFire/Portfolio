#version 330 core

struct Material 
{
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct Light
{
	vec3 position;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 aNormal;
in vec3 fragPos;
in vec2 texCoords;

//uniforms
uniform vec3 viewPos;
uniform Material material;
uniform Light light;

out vec4 fragColor;

void main()
{
	//ambient
	vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoords));

	//diffuse
	vec3 norm = normalize(aNormal);
	vec3 lightDir = normalize(light.position - fragPos);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoords));
	
	//specular
	vec3 reflectDir = reflect(-lightDir, norm);
	vec3 viewDir = normalize(viewPos - fragPos);
	float spec = pow(max(dot(reflectDir, viewDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords));
	
	vec3 result = (ambient + diffuse + specular);
	fragColor = vec4(result, 1.0);
}