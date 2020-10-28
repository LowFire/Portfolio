#include "Init.h"

/********************************************************************
* Function:
* Purpose:
* Parameters:
*
********************************************************************/
bool Init::GLFW()
{
	if (!glfwInit())
	{
		std::cout << "ERROR: Failed to initialize GLFW\n";
		return false;
	}
	return true;
}

/********************************************************************
* Function:
* Purpose:
* Parameters:
*
********************************************************************/
bool Init::GLAD()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "ERROR: Failed to initialize GLAD\n";
		glfwTerminate();
		return false;
	}
	return true;
}

/********************************************************************
* Function:
* Purpose:
* Parameters:
*
********************************************************************/
void Init::version(int verMinor, int verMajor)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, verMinor);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, verMajor);
}

/********************************************************************
* Function:
* Purpose:
* Parameters:
*
********************************************************************/
void Init::profile(int profile)
{
	glfwWindowHint(GLFW_OPENGL_PROFILE, profile);
}