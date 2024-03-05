#include "Camera.h"

Camera::Camera(GLFWwindow* window,float windowWidth, float windowHeight)
{
	this->window = window;
	this->windowWidth = windowWidth;
	this->windowHeight = windowHeight;
	view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
	projection = glm::perspective(glm::radians(FOV), windowWidth / windowHeight, 0.1f, 100.0f);
}

void Camera::moveCamera(float deltaTime)
{
	cameraSpeed *= deltaTime;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
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
	}
}

void Camera::rotateCamera(float xPos, float yPos)
{

	if (!hasMouseMoveOnce)
	{
		xLast = xPos;
		yLast = yPos;
		hasMouseMoveOnce = true;

	}


	float xOffset = xPos - xLast;
	float yOffest = yLast - yPos;
	xLast = xPos;
	yLast = yPos;

	float sensitivity = 0.1f;
	xOffset *= sensitivity;
	yOffest *= sensitivity;

	yaw += xOffset;
	pitch += yOffest;

	if (pitch < -89.0f)
		pitch = -89.0f;
	if (pitch > 89.0f)
		pitch = 89.0f;

	glm::vec3 mouseDirection;
	mouseDirection.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	mouseDirection.y = sin(glm::radians(pitch));

	mouseDirection.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(mouseDirection);


}

void Camera::zoomCamera(float yOffset)
{

	FOV -= yOffset;
	if (FOV < 1.0f)
		FOV = 1.0f;
	if (FOV > 45.0f)
		FOV = 45.0f;

	projection = glm::perspective(glm::radians(FOV), windowWidth / windowHeight, 0.1f, 100.0f);
}

glm::mat4 Camera::getViewMat()
{
	return glm::mat4();
}

glm::mat4 Camera::getProjectionMat()
{
	return glm::mat4();
}

void Camera::updateCamera()
{
	view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);
}
