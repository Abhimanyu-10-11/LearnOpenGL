//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//#include"stb_image.h"
//#include"Shader.h"
//#include"Camera.h"
//#include<iostream>
//using namespace std;
//
//
//float windowWidht = 800.0f;
//float windowHeight = 800.0f;
//
//
//float deltaTime = 0.0f;
//
//bool isCamera1Active = true;
//
//void setFrameBufferSizeCallback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//	glClearColor(1.0f, 0, 0, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glfwSwapBuffers(window);
//}
//
//float mouseXPos, mouseYPos, yScrollOffset;
//glm::vec3 camera1Direction = glm::vec3(0,0,0);
//glm::vec3 camera2Direction = glm::vec3(0, 0, 0);
//void handleInput(GLFWwindow* window, Camera& camera)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
//	{
//		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
//	{
//		camera2Direction = camera.getCameraDirection();
//		camera.setCameradirection(camera1Direction);
//		isCamera1Active = true;
//	}
//	else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
//	{
//		camera1Direction = camera.getCameraDirection();
//		camera.setCameradirection(camera2Direction);
//		isCamera1Active = false;
//	}
//
//	camera.moveCamera(5.0f, deltaTime);
//	camera.updateCamera();
//	camera.rotateCamera(mouseXPos, mouseYPos);
//	camera.zoomCamera(yScrollOffset);
//}
//
//void mouse_callback(GLFWwindow* window, double xPos, double yPos)
//{
//	mouseXPos = xPos;
//	mouseYPos = yPos;
//
//}
//void scroll_callback(GLFWwindow* window, double xOffset, double yOffest)
//{
//	yScrollOffset = yOffest;
//}
//
//
//
//int main()
//{
//
//	glfwInit();
//
//
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	float windowWidht = 800.0f;
//	float windowHeight = 800.0f;
//	GLFWwindow* window = glfwCreateWindow(windowWidht, windowHeight, "Testing", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create winodw";
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
//
//	glfwSetFramebufferSizeCallback(window, setFrameBufferSizeCallback);
//
//	Shader shader("VertexLighting.vert", "FragmentLightingMap.frag");
//
//	Shader lightingShader("VertexLighting.vert", "FragmentLighting.frag");
//
//
//	Camera camera(window, windowWidht, windowHeight);
//	Camera camera2(window, windowWidht, windowHeight);
//
//	float vertices[] = {
//		// positions // normals // texture coords
//			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,	0.0f, 0.0f,
//			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,		1.0f, 0.0f,
//			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,	1.0f, 1.0f,
//			0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,	1.0f, 1.0f,
//			-0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f,		0.0f, 1.0f,
//			-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 	0.0f, 0.0f,
//			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
//			0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,	1.0f, 0.0f,
//			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
//			0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
//			-0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,	0.0f, 1.0f,
//			-0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,		0.0f, 0.0f,
//			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
//			-0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f,		1.0f, 1.0f,
//			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 	 0.0f, 1.0f,
//			-0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 	 0.0f, 1.0f,
//			-0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
//			-0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f,	1.0f, 0.0f,
//			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
//			0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,	1.0f, 1.0f,
//			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
//			0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
//			0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
//			0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,			1.0f, 0.0f,
//			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 	0.0f, 1.0f,
//			0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f,		 1.0f, 1.0f,
//			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,		1.0f, 0.0f,
//			0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,		1.0f, 0.0f,
//			-0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f,		0.0f, 0.0f,
//			-0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 	0.0f, 1.0f,
//			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,		0.0f, 1.0f,
//			0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,	1.0f, 1.0f,
//			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
//			0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
//			-0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f,	0.0f, 0.0f,
//			-0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,	0.0f, 1.0f
//
//	};
//
//	unsigned int VAO;
//	unsigned int VBO;
//
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof
//	(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//	glEnableVertexAttribArray(2);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//
//	unsigned int texture[2];
//	glGenTextures(1, &texture[0]);
//	glBindTexture(GL_TEXTURE_2D, texture[0]);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	int widht, height, urchannel;
//	const char* imageLocation = "WoodenBox.png";
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* data = stbi_load(imageLocation, &widht, &height, &urchannel, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widht, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "FAILED TO LOAD" << imageLocation << "FILE" << endl;
//	}
//
//
//	stbi_image_free(data);
//
//	glGenTextures(1, &texture[1]);
//	glBindTexture(GL_TEXTURE_2D, texture[1]);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//
//	imageLocation = "WoodenBoxSpec.png";
//	stbi_set_flip_vertically_on_load(true);
//	data = stbi_load(imageLocation, &widht, &height, &urchannel, 0);
//
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, widht, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "FAILED TO LOAD" << imageLocation << "FILE" << endl;
//	}
//
//
//	stbi_image_free(data);
//
//	
//
//	glm::vec3 cubePositions[] = {
//			glm::vec3(0.0f, 0.0f, 0.0f),
//			glm::vec3(2.0f, 5.0f, -15.0f),
//			glm::vec3(-1.5f, -2.2f, -2.5f),
//			glm::vec3(-3.8f, -2.0f, -12.3f),
//			glm::vec3(2.4f, -0.4f, -3.5f),
//			glm::vec3(-1.7f, 3.0f, -7.5f),
//			glm::vec3(1.3f, -2.0f, -2.5f),
//			glm::vec3(1.5f, 2.0f, -2.5f),
//			glm::vec3(1.5f, 0.2f, -1.5f),
//			glm::vec3(-1.3f, 1.0f, -1.5f)
//	};
//
//	glm::vec3 lightPos(1.0f, 1.0f, 2.0f);
//	glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
//	glm::mat4 lightModel = glm::mat4(1.0f);
//	lightModel = glm::translate(lightModel, lightPos);
//	lightModel = glm::scale(lightModel,glm::vec3(0.2f, 0.2f, 0.2f));
//
//
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, texture[0]);
//	glActiveTexture(GL_TEXTURE1);
//	glBindTexture(GL_TEXTURE_2D, texture[1]);
//	
//
//
//	shader.use();
//	shader.setTexture("material.diffuse", 0);
//	shader.setTexture("material.specular", 1);
//	shader.setFloat("material.shininess", 32.0f);
//	shader.setMat4("view", camera.view);
//	shader.setMat4("projection", camera.projection);
//
//	
//
//	
//	lightingShader.use();
//	lightingShader.setVec3("lightColor", lightColor);
//	lightingShader.setMat4("view", camera.view);
//	lightingShader.setMat4("projection", camera.projection);
//
//	glEnable(GL_DEPTH_TEST);
//
//
//	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//	glfwSetCursorPosCallback(window, mouse_callback);
//	glfwSetScrollCallback(window, scroll_callback);
//
//
//
//
//
//	float currentFrame = 0.0f;
//	float lastFrame = 0.0f;
//	while (!glfwWindowShouldClose(window))
//	{
//		currentFrame = glfwGetTime();
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//		shader.use();
//		
//		
//		
//
//	
//		
//		glm::vec3 diffuseLightColor = lightColor * glm::vec3(1.f);
//		glm::vec3 ambientLightColor = diffuseLightColor * glm::vec3(.2f);
//
//
//		shader.setVec3("light.position", lightPos);
//		shader.setVec3("light.ambient", ambientLightColor);
//		shader.setVec3("light.diffuse", diffuseLightColor); 
//		shader.setVec3("light.specular", glm::vec3(1.0f, 1.0f, 1.0f));
//
//
//		
//
//		if (isCamera1Active)
//		{
//			handleInput(window, camera);
//			shader.use();
//			shader.setMat4("view", camera.view);
//			shader.setMat4("projection", camera.projection);
//
//			lightingShader.use();
//			lightingShader.setMat4("view", camera.view);
//			lightingShader.setMat4("projection", camera.projection);
//
//
//		}
//		else
//		{
//
//			handleInput(window, camera2);
//			shader.use();
//			shader.setMat4("view", camera2.view);
//			shader.setMat4("projection", camera2.projection);
//
//			lightingShader.use();
//			lightingShader.setMat4("view", camera2.view);
//			lightingShader.setMat4("projection", camera2.projection);
//
//		}
//		for (unsigned int i = 0; i < 10; i++)
//		{
//			glm::mat4 model = glm::mat4(1.0f);
//			model = glm::translate(model, cubePositions[i]);
//
//			if (i % 3 == 0)
//			{
//				float angle = 20.0f * i;
//				model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle),
//					glm::vec3(1.0f, 0.3f, 0.5f));
//
//			}
//
//			shader.use();
//			shader.setVec3("viewPos", camera.getCameraPos());
//			shader.setMat4("model", model);
//			glDrawArrays(GL_TRIANGLES, 0, 36);
//		}
//
//		float lightSpeed = 1.0f * deltaTime;
//		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
//		{
//			glm::vec3 moveLight = glm::vec3(.0f, 0.0f, -lightSpeed);
//			lightModel = glm::translate(lightModel, moveLight);
//			lightPos+=moveLight;
//
//		}
//		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
//		{
//			glm::vec3 moveLight = glm::vec3(.0f, 0.0f, lightSpeed );
//			lightModel = glm::translate(lightModel, moveLight);
//			lightPos+=moveLight;
//
//		}
//		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//		{
//			glm::vec3 moveLight = glm::vec3(.0f, lightSpeed, 0.f );
//			lightModel = glm::translate(lightModel, moveLight);
//			lightPos+=moveLight;
//
//		}
//		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
//		{
//			glm::vec3 moveLight = glm::vec3(.0f, -lightSpeed, 0.f  );
//			lightModel = glm::translate(lightModel, moveLight);
//			lightPos+=moveLight;
//
//		}
//
//		lightingShader.use();
//		lightingShader.setMat4("model", lightModel);
//		lightingShader.setVec3("lightColor", lightColor);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glDeleteBuffers(1, &VBO);
//	glDeleteVertexArrays(1, &VAO);
//	glfwDestroyWindow(window);
//	glfwTerminate();
//	return 0;
//
//}
