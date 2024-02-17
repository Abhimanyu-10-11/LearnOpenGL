//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<glm/glm.hpp>
//#include<glm/gtc/matrix_transform.hpp>
//#include<glm/gtc/type_ptr.hpp>
//#include"stb_image.h"
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
//	float windowWidht = 800;
//	float windowHeight = 800;
//	GLFWwindow* window = glfwCreateWindow(windowWidht, windowHeight, "Testing", NULL, NULL);
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
//	Shader shader("VertexShaderCoordinateSystem.vert", "FragmentShaderCoordinateSystem.frag");
//
//	float vertices[] = {
//			0.5f, 0.5f, 0.0f, 1.0f,1.0f,// top right
//			0.5f, -0.5f, 0.0f,1.0f,0.0f, // bottom right
//			-0.5f, -0.5f, 0.0f, 0.0f,0.0f, // bottom left
//			-0.5f, 0.5f, 0.0f,0.0f,1.0f // top left
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
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof
//	(float), (void*)(3 * sizeof(float)));
//	glEnableVertexAttribArray(1);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//
//	unsigned int texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	int widht, height, urchannel;
//	const char* imageLocation = "awesomeface.png";
//	stbi_set_flip_vertically_on_load(true);
//	unsigned char* data = stbi_load(imageLocation, &widht, &height, &urchannel, 0);
//	if (data)
//	{
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widht, height, 0, GL_RGBA,GL_UNSIGNED_BYTE,data);
//		glGenerateMipmap(GL_TEXTURE_2D);
//	}
//	else
//	{
//		std::cout << "FAILED TO LOAD awesomeface.png FILE" << endl;
//	}
//
//
//	stbi_image_free(data);
//
//	glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);
//
//
//
//
//
//
//		
//	glm::mat4 model,view,projection = glm::mat4(1.0f);
//	model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
//
//	view = glm::translate(view, glm::vec3(0, 0, -3.0f));
//
//	projection = glm::perspective(glm::radians(45.0f),windowWidht/windowHeight,0.1f,100.0f);
//
//	shader.use();
//	glUniformMatrix4fv(glGetUniformLocation(shader.ID,"model"), 1, GL_FALSE, glm::value_ptr(model));
//	glUniformMatrix4fv(glGetUniformLocation(shader.ID,"view"), 1, GL_FALSE, glm::value_ptr(view));
//	glUniformMatrix4fv(glGetUniformLocation(shader.ID,"projection"), 1, GL_FALSE, glm::value_ptr(projection));
//	
//	
//
//	while(!glfwWindowShouldClose(window))
//	{
//		handleInput(window);
//		glClearColor(0.2f, 0.3f, 0.3f, 0.5f);
//		glClear(GL_COLOR_BUFFER_BIT);
//		shader.use();
//		glBindTexture(GL_TEXTURE_2D, texture);
//		glBindVertexArray(VAO);
//		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
