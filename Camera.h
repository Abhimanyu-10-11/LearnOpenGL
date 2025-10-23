#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>



class Camera
{

private:
	glm::vec3 cameraPosition = glm::vec3(0, 0, -3);
	glm::vec3 cameraUp = glm::vec3(0, 1.0f, 0);
	glm::vec3 cameraFront = glm::vec3(0, 0, -1.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));

	GLFWwindow* window;
	float windowWidth, windowHeight;
	bool hasMouseMoveOnce = false;
	float yaw = -90.f;
	float pitch = 0.f;
	float xLast = 0.0f, yLast = 0.0f;
	float FOV = 45.0f;
	float cameraSpeed = 0.0f;
	glm::vec3 cameraDirection;

public:
	glm::mat4  view, projection = glm::mat4(1.0f);
	Camera(GLFWwindow* window,float windowWidth,float windowHeight);
	glm::vec3 getCameraPos();
	void moveCamera(float cameraSpeed, float deltaTime);
	void rotateCamera(float xPos, float yPos);
	void zoomCamera(float yOffset);
	glm::mat4 getViewMat();
	glm::mat4 getProjectionMat();
	void updateCamera();
	glm::vec3 getCameraDirection();
	void setCameradirection(glm::vec3);



};



#endif // CAMERA
