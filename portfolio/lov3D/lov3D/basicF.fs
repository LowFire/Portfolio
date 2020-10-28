#version 330 core

//inputs
in vec3 aNormal;
in vec3 fragPos;
in vec2 texCoords;

//outputs
out vec4 fragColor;

//For textures
struct Material 
{
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

//Light structures
struct DirLight
{
	vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

struct PointLight {    
    vec3 position;
    
    float constant;
    float lin;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};  

/*struct Light
{
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;
	
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	
	float constant;
	float linear;
	float quadratic;
};*/

//Functions for calculating lighting.
vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir);
vec3 calcPointLight(PointLight light, vec3 normal, vec3 fraPos, vec3 viewDir);

//uniforms
#define NR_POINT_LIGHTS 4
uniform vec3 viewPos;
uniform Material material;
uniform DirLight dirLight;
uniform PointLight pointLights[NR_POINT_LIGHTS];

void main()
{
	vec3 result = vec3(0.0);
	vec3 viewDir = normalize(viewPos - fragPos);

	//Directional light
	result = calcDirLight(dirLight, aNormal, viewDir);

	for(int i = 0; i < NR_POINT_LIGHTS; i++)
		result += calcPointLight(pointLights[i], aNormal, fragPos, viewDir);

	fragColor = vec4(result, 1.0);
}

//function definitions
vec3 calcDirLight(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);
    // diffuse shading
    float diff = max(dot(normal, lightDir), 0.0);
    // specular shading
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    // combine results
    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, texCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, texCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords));
    return (ambient + diffuse + specular);
}

vec3 calcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir)
{
	vec3 lightdir = normalize(light.position - fragPos);
    // diffuse shading
    float diff = max(dot(normal, lightdir), 0.0);
    // specular shading
    vec3 reflectdir = reflect(-lightdir, normal);
    float spec = pow(max(dot(viewDir, reflectdir), 0.0), material.shininess);
    // attenuation
    float distance    = length(light.position - fragPos);
    float attenuation = 1.0 / (light.constant + light.lin * distance + 
  			     light.quadratic * (distance * distance));    
    // combine results
    vec3 ambient  = light.ambient  * vec3(texture(material.diffuse, texCoords));
    vec3 diffuse  = light.diffuse  * diff * vec3(texture(material.diffuse, texCoords));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, texCoords));
    ambient  *= attenuation;
    diffuse  *= attenuation;
    specular *= attenuation;
    return (ambient + diffuse + specular);
}