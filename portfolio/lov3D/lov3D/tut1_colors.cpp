#include <iostream>
#include <string>
#include <cmath>

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#include "Graphical.h"
#include "Camera.h"
#include "Shader.h"
#include "PointLight.h"



void processInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void processInput(GLFWwindow * window, Camera &camera)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.moveForward();
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.moveBackward();
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.moveLeft();
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.moveRight();
}

void processMouseInput(GLFWwindow * window, Camera &camera)
{
	static bool firstMouse = true;

	double xpos;
	double ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	static float lastXpos = xpos;
	static float lastYpos = ypos;

	if (firstMouse)
	{
		lastXpos = xpos;
		lastYpos = ypos;
		firstMouse = false;
	}

	double xoffset = xpos - lastXpos;
	double yoffset = lastYpos - ypos;
	lastXpos = xpos;
	lastYpos = ypos;

	static float pitch = 0;
	static float yaw = 0;

	float sensitivity = 0.1f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	pitch += yoffset;
	yaw += xoffset;

	if (pitch >= 85)
		pitch = 85;
	else if (pitch <= -85)
		pitch = -85;

	glm::vec3 front;
	front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	front.y = sin(glm::radians(pitch));
	front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
	camera.setFront(glm::normalize(front));
	
}

void window_resize_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

float getDistance(const glm::vec3 &objPos1, const glm::vec3 &objPos2)
{
	glm::vec3 difference = objPos1 - objPos2;
	float distance = (difference.x * difference.x) +
		(difference.y * difference.y) +
		(difference.z * difference.z);
	distance = sqrt(distance);
	return distance;
}

void error_callback(int error, const char* description)
{
	puts(description);
}

int main()
{
	//Graphical engine object
	Graphical engine;



	//init glfw
	//---------------
	if (!engine.init.GLFW())
	{
		getchar();
		return -1;
	}



	//Set Versions
	//---------------
	engine.init.profile(GLFW_OPENGL_CORE_PROFILE);
	engine.init.version(3, 4);



	//form window
	//---------------
	engine.win.setName("Lov3D");
	engine.win.setHeight(1080);
	engine.win.setWidth(1920);
	if (!engine.win.formWindow())
	{
		getchar();
		return -1;
	}
	GLFWwindow * window = engine.win.getWindow();



	//init glad
	//---------------
	if (!engine.init.GLAD())
	{
		getchar();
		return -1;
	}



	//Callbacks
	//---------------
	glfwSetWindowSizeCallback(window, window_resize_callback);
	glfwSetErrorCallback(error_callback);


	//Vertex Data
	//--------------

	float vertices[] = {
		// positions          // normals           // texture coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	glm::vec3 pointLightPositions[] = {
		glm::vec3(0.7f,  0.2f,  2.0f),
		glm::vec3(2.3f, -3.3f, -4.0f),
		glm::vec3(-4.0f,  2.0f, -12.0f),
		glm::vec3(0.0f,  0.0f, -3.0f)
	};


	//Buffer Objects
	//---------------
	unsigned int VBO;
	//unsigned int EBO;
	unsigned int VAO;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	//lightVAO
	unsigned int lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(0);

	//Create Shader and Camera
	//------------------
	Shader cubeShader("basicV.vs", "basicF.fs", "cube");
	Shader lightShader("light.vs", "light.fs", "light");
	Camera camera(float(engine.win.getWidth()) / float(engine.win.getHeight()));

	cubeShader.use();
	cubeShader.setVec3("material.ambient", glm::vec3(1.0f, 0.5f, 0.31f));
	cubeShader.setFloat("material.shininess", 128.0f);

	camera.setView(glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), 
		glm::vec3(0.0f, 0.0f, -3.0f), 
		glm::vec3(0.0f, 1.0f, 0.0f)));

	glm::mat4 view = camera.getView();
	glm::mat4 projection = camera.getProjection();

	cubeShader.setMat4("view", view);
	cubeShader.setMat4("projection", projection);

	lightShader.use();
	lightShader.setMat4("view", view);
	lightShader.setMat4("projection", projection);

	glm::mat4 objectModel;
	glm::vec3 objectPos = { 0.0f, 5.0f, -3.0f };
	objectModel = glm::translate(objectModel, objectPos);
	//objectModel = glm::rotate(objectModel, glm::radians(70.0f), glm::vec3(0.5f, 0.0f, 0.5f));

	//glm::vec3 origin = { 0.0f, 5.0f, -3.0f };
	DeltaTime deltaTime;

   //Point lights

   std::vector <PointLight> pointLights;
   for (int i = 0; i < 4; i++)
   {
      pointLights.push_back(PointLight(pointLightPositions[i]));

      cubeShader.setVec3("pointLights[" + std::to_string(i) + "].position", 
         pointLights.at(i).getPos());

      cubeShader.setFloat("pointLights[" + std::to_string(i) + "].constant",
         pointLights.at(i).getConstant());
      cubeShader.setFloat("pointLights[" + std::to_string(i) + "].lin",
         pointLights.at(i).getLinear());
      cubeShader.setFloat("pointLights[" + std::to_string(i) + "].quadratic",
         pointLights.at(i).getQuadratic());

      cubeShader.setVec3("pointLights[" + std::to_string(i) + "].ambient",
         pointLights.at(i).getAmbient());
      cubeShader.setVec3("pointLights[" + std::to_string(i) + "].diffuse",
         pointLights.at(i).getDiffuse());
      cubeShader.setVec3("pointLights[" + std::to_string(i) + "].specular",
         pointLights.at(i).getSpecular());
   }

	//textures
	Texture container("textures/container2.png", GL_TEXTURE_2D, GL_TEXTURE0);
	Texture specularMap("textures/container2_specular2.png", GL_TEXTURE_2D, GL_TEXTURE1);
	cubeShader.use();
	cubeShader.setInt("material.diffuse", 0);
	cubeShader.setInt("material.specular", 1);

	//Set Options
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		processInput(window);
		processInput(window, camera);
		processMouseInput(window, camera);
		deltaTime.update();
		camera.update();
		camera.setDeltaSpeed(camera.getSpeed() * deltaTime.getTime());
		view = camera.getView();

		lightShader.use();
		glBindVertexArray(lightVAO);
		lightShader.setMat4("view", view);
		glDrawArrays(GL_TRIANGLES, 0, 36);


		cubeShader.use();
		container.use();
		specularMap.use();
		glBindVertexArray(VAO);

		cubeShader.setMat4("view", view);
		cubeShader.setVec3("viewPos", camera.getPos());
      cubeShader.setVec3("dirLight.direction", glm::vec3(0.5f, 0.5f, 1.0f));
      cubeShader.setVec3("dirLight.ambient", glm::vec3(0.1f));
      cubeShader.setVec3("dirLight.diffuse", glm::vec3(1.0f));
      cubeShader.setVec3("dirLight.specular", glm::vec3(1.0f));

		/*cubeShader.setVec3("light.position", camera.getPos());
		cubeShader.setVec3("light.direction", camera.getFront());
		cubeShader.setFloat("light.cutOff", glm::cos(glm::radians(12.5f)));
		cubeShader.setFloat("light.outerCutOff", glm::cos(glm::radians(17.5f)));
		cubeShader.setVec3("light.ambient", glm::vec3(0.1f));
		cubeShader.setVec3("light.diffuse", glm::vec3(1.0f));
		cubeShader.setVec3("light.specular", glm::vec3(1.0f));
		cubeShader.setFloat("light.constant", 1.0f);
		cubeShader.setFloat("light.linear", 0.09f);
		cubeShader.setFloat("light.quadratic", 0.032f);*/

		for (unsigned int i = 0; i < 10; i++)
		{
			glm::mat4 model;
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			cubeShader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glBindVertexArray(lightVAO);
		lightShader.use();
		for (int i = 0; i < 4; i++)
		{
			glm::mat4 model;
			model = glm::translate(model, pointLightPositions[i]);
			lightShader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteVertexArrays(1, &lightVAO);
	glfwTerminate();

	return 0;
}