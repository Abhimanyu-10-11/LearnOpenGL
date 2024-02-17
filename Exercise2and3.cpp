//#include<glad/glad.h>
//#include<GLFW/glfw3.h>
//#include<iostream>
//using namespace std;
//
////2. Now create the same 2 triangles using two different VAOs and 
//// VBOs for their data
//// 
////3. Create two shader programs where the second program uses a 
//// different fragment shader
////that outputs the color yellow; draw both triangles again where 
//// one outputs the color yellow.
//
//
//const char* vertexShaderSource =
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//" gl_Position = vec4(aPos.x	, aPos.y, aPos.z, 1.0);\n"
//
//"}\0";
//
//const char* fragmentShaderSource =
//"#version 330 core\n"
//"out vec4 FragColor;\n"
//"uniform vec4 ourColor;"
//"void main()\n"
//"{\n"
//"    FragColor = ourColor;\n"
//"}\0";
//
//const char* fragmentShader2Source = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//"}\n\0";
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
//
//	unsigned int vertexShader;
//	vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		cout << "ERROR: VERTEX SHADER: COMPILATION FAILED " << infoLog<<endl;
//	}
//
//	unsigned int fragmentShader[2];
//	fragmentShader[0] = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader[0], 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader[0]);
//
//	glGetShaderiv(fragmentShader[0], GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader[0], 512, NULL, infoLog);
//		cout << "ERROR: FRAGMENT SHADER: COMPILATION FAILED " << infoLog << endl;
//	}
//
//	unsigned int shaderProgram[2];
//	shaderProgram[0] = glCreateProgram();
//	glAttachShader(shaderProgram[0], vertexShader);
//	glAttachShader(shaderProgram[0], fragmentShader[0]);
//	glLinkProgram(shaderProgram[0]);
//
//	glGetProgramiv(shaderProgram[0], GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram[0], 512, NULL, infoLog);
//		cout << "ERROR: SHADER PROGRAM: LINKING FAILED " << infoLog << endl;
//	}
//
//	fragmentShader[1] = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader[1], 1, &fragmentShader2Source, NULL);
//	glCompileShader(fragmentShader[1]);
//
//	glGetShaderiv(fragmentShader[1], GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader[0], 512, NULL, infoLog);
//		cout << "ERROR: FRAGMENT SHADER 2: COMPILATION FAILED " << infoLog << endl;
//	}
//
//	shaderProgram[1] = glCreateProgram();
//	glAttachShader(shaderProgram[1], vertexShader);
//	glAttachShader(shaderProgram[1], fragmentShader[1]);
//	glLinkProgram(shaderProgram[1]);
//
//	glGetProgramiv(shaderProgram[1], GL_LINK_STATUS, &success);
//	if (!success)
//	{
//		glGetProgramInfoLog(shaderProgram[1], 512, NULL, infoLog);
//		cout << "ERROR: SHADER PROGRAM 2: LINKING FAILED " << infoLog << endl;
//	}
//
//
//
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader[0]);
//	glDeleteShader(fragmentShader[1]);
//
//	float vertices[] = {
//		0.5f, 0.5f, 0.0f, // top right
//			0.5f, -0.5f, 0.0f, // bottom right
//			-0.5f, -0.5f, 0.0f, // bottom left
//	};
//	float vertices2[] = {
//			0.4f, 0.5f, 0.0f, // top right
//			-0.6f, 0.5f, 0.0f, // bottom right
//			-0.6f, -0.5f, 0.0f, // bottom left
//	};
//
//
//	/*
//	* this also work 
//	unsigned int VAO;
//	unsigned int VBO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);;
//	glBindVertexArray(VAO);
//
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	unsigned int VAO2;
//	unsigned int VBO2;
//	glGenVertexArrays(1, &VAO2);
//	glGenBuffers(1, &VBO2);
//	glBindVertexArray(VAO2);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO2);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2,GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//	*/
//
//	//alternative method
//
//	unsigned int VAO[2];
//	unsigned int VBO[2];
//	glGenVertexArrays(2, VAO);
//	glGenBuffers(2, VBO);;
//
//
//	glBindVertexArray(VAO[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	glBindVertexArray(VAO[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	int vertexColorLocation = glGetUniformLocation(shaderProgram[0], "ourColor");
//
//	while(!glfwWindowShouldClose(window))
//	{
//		handleInput(window);
//		glClear(GL_COLOR_BUFFER_BIT);
//		glUseProgram(shaderProgram[0]);
//		float time = glfwGetTime();
//		float greenValue = (sin(time) / 2.0f) + 0.5f;
//		glUniform4f(vertexColorLocation, 0, greenValue, 0, 1.0f);
//		glBindVertexArray(VAO[0]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);	
//		glUseProgram(shaderProgram[1]);
//		glBindVertexArray(VAO[1]);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		/* above comment drawing part
//		glBindVertexArray(VAO);
//		glDrawArrays(GL_TRIANGLES, 0, 3);	
//		glBindVertexArray(VAO2);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		*/
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	glfwDestroyWindow(window);
//	glfwTerminate();
//	return 0;
//
//}