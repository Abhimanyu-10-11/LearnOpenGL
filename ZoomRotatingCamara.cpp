#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include"stb_image.h"
#include"Shader.h"
#include"Camera.h"
#include<iostream>
using namespace std;

float windowWidht = 800.0f;
float windowHeight = 800.0f;



//glm::vec3 cameraPosition = glm::vec3(0, 0, -3);
//glm::vec3 cameraUp = glm::vec3(0, 1.0f, 0);
//glm::vec3 cameraFront = glm::vec3(0, 0, -1.0f);
//glm::vec3 cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));

float deltaTime = 0.0f;

void setFrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	glClearColor(1.0f, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
}

void handleInput(GLFWwindow* window,Camera &camera)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	camera.moveCamera(deltaTime);
	
	/*if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPosition += cameraSpeed * cameraFront;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPosition -= cameraSpeed * cameraFront;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));
		cameraPosition += cameraSpeed * cameraRight;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));
		cameraPosition -= cameraSpeed * cameraRight;
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		cameraPosition += cameraSpeed * cameraUp;
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		cameraPosition -= cameraSpeed * cameraUp;
	}*/


}

//bool hasMouseMoveOnce = false;
//
//float yaw = -90.f;
//float pitch = 0.f;
//float xLast = windowWidht/2, yLast = windowHeight/2;
void mouse_callback(GLFWwindow* window, double xPos, double yPos)
{
	//if (!hasMouseMoveOnce)
	//{
	//	xLast = xPos;
	//	yLast = yPos;
	//	hasMouseMoveOnce = true;
	//
	//}


	//float xOffset = xPos - xLast;
	//float yOffest = yLast - yPos;
	//xLast = xPos;
	//yLast = yPos;

	//float sensitivity = 0.1f;
	//xOffset *= sensitivity;
	//yOffest *= sensitivity;

	//yaw += xOffset;
	//pitch += yOffest;

	//if (pitch < -89.0f)
	//	pitch = -89.0f;
	//if (pitch > 89.0f)
	//	pitch = 89.0f;

	//glm::vec3 mouseDirection;
	//mouseDirection.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	//mouseDirection.y = sin(glm::radians(pitch));

	//mouseDirection.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	//cameraFront = glm::normalize(mouseDirection);


}
//float FOV = 45.0f;
//glm::mat4  view, projection = glm::mat4(1.0f);
void scroll_callback(GLFWwindow* window, double xOffset, double yOffest)
{
	/*FOV -= (float)yOffest;
	if (FOV < 1.0f)
		FOV = 1.0f;
	if (FOV > 45.0f)
		FOV = 45.0f;

	projection = glm::perspective(glm::radians(FOV), windowWidht / windowHeight, 0.1f, 100.0f);*/
}



int main()
{

	glfwInit();


	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	float windowWidht = 800.0f;
	float windowHeight = 800.0f;
	GLFWwindow* window = glfwCreateWindow(windowWidht, windowHeight, "Testing", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create winodw";
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	
	glfwSetFramebufferSizeCallback(window, setFrameBufferSizeCallback);

	Shader shader("VertexShaderCoordinateSystem.vert", "FragmentShaderCoordinateSystem.frag");
	Camera camera(window, windowWidht, windowHeight);

	float vertices[] = {
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
			0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f

	};

	unsigned int indices[] =
	{
		0,1,3,
		1,2,3
	};


	unsigned int VAO;
	unsigned int VBO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);


	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof
	(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int widht, height, urchannel;
	const char* imageLocation = "wall.jpg";
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(imageLocation, &widht, &height, &urchannel, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widht, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "FAILED TO LOAD wall.jpg FILE" << endl;
	}


	stbi_image_free(data);

	glm::vec3 cubePositions[] = {
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(2.0f, 5.0f, -15.0f),
			glm::vec3(-1.5f, -2.2f, -2.5f),
			glm::vec3(-3.8f, -2.0f, -12.3f),
			glm::vec3(2.4f, -0.4f, -3.5f),
			glm::vec3(-1.7f, 3.0f, -7.5f),
			glm::vec3(1.3f, -2.0f, -2.5f),
			glm::vec3(1.5f, 2.0f, -2.5f),
			glm::vec3(1.5f, 0.2f, -1.5f),
			glm::vec3(-1.3f, 1.0f, -1.5f)
	};

	glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);

	/*view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);*/

	/*projection = glm::perspective(glm::radians(FOV), windowWidht / windowHeight, 0.1f, 100.0f);*/

	shader.use();
	shader.setMat4("view", camera.view);
	shader.setMat4("projection", camera.projection);
	
	glEnable(GL_DEPTH_TEST);


	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glfwSetCursorPosCallback(window,mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	


	float currentFrame = 0.0f;
	float lastFrame = 0.0f;
	while (!glfwWindowShouldClose(window))
	{
		currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		handleInput(window,camera);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shader.use();
		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO);

		/*view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);*/
		camera.updateCamera();

		shader.setMat4("view", camera.view);
		shader.setMat4("projection", camera.projection);

	/*	shader.setMat4("view", view);
		shader.setMat4("projection", projection);*/

		for (unsigned int i = 0; i < 10; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);

			if (i % 3 == 0)
			{
				float angle = 20.0f * i;
				model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle),
					glm::vec3(1.0f, 0.3f, 0.5f));

			}
			glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;

}
