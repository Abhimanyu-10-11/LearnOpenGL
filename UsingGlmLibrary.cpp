//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//#include"Shader.h"
//#include<iostream>
//using namespace std;
//
//
//
//
//void setFrameBufferSizeCallback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//	glClearColor(1.0f, 0, 0, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glfwSwapBuffers(window);
//}
//
//void handleInput(GLFWwindow* window)
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
//}
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
//
//	GLFWwindow* window = glfwCreateWindow(800, 800, "Testing", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create winodw";
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//
//	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
//	glfwSetFramebufferSizeCallback(window, setFrameBufferSizeCallback);
//
//	Shader shader("VertexShaderWithTransform.vert", "FragmentShader.frag");
//	shader.use();
//	glm::mat4 trans = glm::mat4(1.0f);
//	trans = glm::scale(trans,glm::vec3(1.5,0.5,0.5));
//
//	glUniformMatrix4fv(glGetUniformLocation(shader.ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
//
//	float vertices[] = {
//			0.5f, 0.5f, 0.0f, // top right
//			0.5f, -0.5f, 0.0f, // bottom right
//			-0.5f, -0.5f, 0.0f, // bottom left
//			-0.5f, 0.5f, 0.0f // top left
//	};
//
//	unsigned int indices[] =
//	{
//		0,1,3,
//		1,2,3
//	};
//
//
//	unsigned int VAO;
//	unsigned int VBO;
//	unsigned int EBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//	glGenBuffers(1, &EBO);
//	glBindVertexArray(VAO);
//
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	
//
//	while (!glfwWindowShouldClose(window))
//	{
//		handleInput(window);
//		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
//		{
//			trans = glm::rotate(trans, glm::radians(30.0f), glm::vec3(.0f, 1.0f, .0f));
//			trans = glm::translate(trans, glm::vec3(.0001f, .0001f, 0.0f));
//			glUniformMatrix4fv(glGetUniformLocation(shader.ID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));
//			
//		}
//		glClear(GL_COLOR_BUFFER_BIT);
//		shader.use();
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
