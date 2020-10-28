#include "Shader.h"


Shader::Shader(std::string vertexPath, std::string fragmentPath, std::string name)
{
	this->name = name;//Set name


	//strings for holding shader source code
	std::string vertexSourceString;
	std::string fragmentSourceString;

	try
	{
		//Get shader source code
		std::ifstream fin(vertexPath);
		if (fin.fail())
			throw "ERROR: Failed to open vertex shader file: " + vertexPath + '\n';
		while (fin.peek() != EOF)
			vertexSourceString += fin.get();
		fin.close();

		fin.open(fragmentPath);
		if (fin.fail())
			throw "ERROR: Failed to open fragment shader file: " + fragmentPath + '\n';
		while (fin.peek() != EOF)
			fragmentSourceString += fin.get();
		fin.close();

		//Pass string pointer to char *
		const char * vertexSource = vertexSourceString.c_str();
		const char * fragmentSource = fragmentSourceString.c_str();

		//Create shader objects
		unsigned int vertexID = glCreateShader(GL_VERTEX_SHADER);
		unsigned int fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

		glShaderSource(vertexID, 1, &vertexSource, NULL);
		glShaderSource(fragmentID, 1, &fragmentSource, NULL);

		//Compile shaders
		glCompileShader(vertexID);
		int success;
		char infolog[512];
		glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexID, 512, NULL, infolog);
			throw "ERROR: Vertex shader, \"" + vertexPath + "\", in \"" + name + "\" has failed to compile\n" + std::string(infolog);
		}

		glCompileShader(fragmentID);
		glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentID, 512,	NULL, infolog);
			throw "ERROR: Fragment shader, \"" + fragmentPath + "\", in \"" + name + "\" has failed to compile\n" + std::string(infolog);
		}

		//Link shader program
		id = glCreateProgram();
		glAttachShader(id, vertexID);
		glAttachShader(id, fragmentID);
		glLinkProgram(id);

		glGetProgramiv(id, GL_LINK_STATUS, &success); //Check for linking errors
		if (!success)
		{
			glGetProgramInfoLog(id, 512, NULL, infolog);
			throw "ERROR: Shader program in \"" + name + "\" has failed to link\n" + std::string(infolog);
		}

		glDeleteShader(vertexID);
		glDeleteShader(fragmentID);
	}
	catch (const std::string message)
	{
		std::cout << message;
	}
}


void Shader::use()
{
	glUseProgram(id);
}


void Shader::setInt(const std::string &name, const int aNumber)
{
	if (validate())
	{
		int uniId = glGetUniformLocation(id, name.c_str());
		glUniform1i(uniId, aNumber);
	}

}


void Shader::setBool(const std::string &name, const bool aBool)
{
	if (validate())
	{
		int uniId = glGetUniformLocation(id, name.c_str());
		glUniform1i(uniId, aBool);
	}

}


void Shader::setFloat(const std::string &name, const float aFloat)
{
	if (validate())
		glUniform1f(glGetUniformLocation(id, name.c_str()), aFloat);

}


void Shader::setMat4(const std::string &name, const glm::mat4 &aMatrix)
{
	if (validate())
		glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, glm::value_ptr(aMatrix));

}

void Shader::setVec3(const std::string &name, const glm::vec3 &aVec)
{
	if (validate())
		glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, glm::value_ptr(aVec));
}

bool Shader::validate()
{
	if (id <= 0)
	{
		return false;
	}
	return true;
}