//#include<glad/glad.h>
//#include <GLFW/glfw3.h>
//#include<iostream>
//using namespace std;
//
//
//const char* vertexShaderSource =
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"layout (location = 1) in vec3 aColor;"
//"out vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"ourColor = aColor;\n"
//"}\0";
//
//const char* fragmentShaderSource =
//"#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec3 ourColor;\n"
//"void main()\n"
//"{\n"
//"    FragColor = vec4(ourColor,1.0f);\n"
//"}\0";
//
///*
//    const char* vertexShaderSource = 
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
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
//*/
//
///* passing data form one shader to another
//const char* vertexShaderSource = 
//"#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"out vec4 vertexColor;\n"
//"void main()\n"
//"{\n"
//" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"vertexColor = vec4(0.5, 0.0, 0.0, 1.0);"
//"}\0";
//
//const char* fragmentShaderSource =
//"#version 330 core\n"
//"out vec4 FragColor;\n"
//"in vec4 vertexColor;\n"
//"void main()\n"
//"{\n"
//"    FragColor = vertexColor;\n"
//"}\0";*/
//
//void framebuffer_size_callback(
//    GLFWwindow* window, int width, int height)
//{
//
//    glViewport(0, 0, width, height);
//    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glfwSwapBuffers(window);
//}
//
//void handleInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//    {
//        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//        glfwSwapBuffers(window);
//        glfwSetWindowShouldClose(window, true);
//    }
//    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
//    {
//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//    }  
//}
//
//
//int main(void)
//{
//    glfwInit();
//    
//    
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWwindow* window = glfwCreateWindow(800, 800, "LearningOpengl", NULL, NULL);
//    if (window == NULL)
//    {
//        cout << "Failed to laod window" << endl;
//        glfwDestroyWindow(window);
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//   
//    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
//  
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//    unsigned int vertexShader;
//    vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    unsigned int fargmentShader;
//    fargmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fargmentShader, 1, &fragmentShaderSource, NULL);
//    int fragSucces;
//    char fragInfoLog[512];
//    glCompileShader(fargmentShader);
//    glGetShaderiv(fargmentShader, GL_COMPILE_STATUS, &fragSucces);
//    if (!success)
//    {
//        glGetShaderInfoLog(fargmentShader, 512, NULL, fragInfoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << fragInfoLog << std::endl;
//    }
//
//    unsigned int shaderProgram;
//    shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fargmentShader);
//    glLinkProgram(shaderProgram);
//
//    int shaderProgramSucces;
//    char shaderProgInfo[512];
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &shaderProgramSucces);
//    if (!shaderProgramSucces)
//    {
//        glGetProgramInfoLog(shaderProgram, 512, NULL, shaderProgInfo);
//        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << shaderProgInfo << std::endl;
//    }
//
//    glDeleteShader(vertexShader);
//    glDeleteShader(fargmentShader);
//
//    float vertices[] = 
//    {
//        // positions        // colors
//       0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // bottom right
//       -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom left
//       0.0f, 0.5f, 0.0f,    0.0f, 0.0f, 1.0f, // top
//       -0.5f, 0.5f, 0.0f,   0.0f, 1.0f, 0.0f // top left
//
//    };
//
//    unsigned int indices[] =
//    {
//        0,1,3,
//        1,2,3
//    };
//
//   unsigned int VAO;
//   unsigned int VBO;
//   unsigned int EBO;
//   glGenVertexArrays(1,&VAO);
//   glGenBuffers(1, &VBO);
//   glGenBuffers(1, &EBO);
//   glBindVertexArray(VAO);
//
//   glBindBuffer(GL_ARRAY_BUFFER, VBO);
//   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//   glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//   //position attribute
//       glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),(void*)0);
//   glEnableVertexAttribArray(0);
//   // color attribute
//   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),(void*)(3 * sizeof(float)));
//   glEnableVertexAttribArray(1);
//
//
//  
//   
//    glClearColor(1.0f, 0, 0, 1.0f);
//
//     /*   int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//        if (vertexColorLocation == -1)
//            std::cout << "UNABLE TO FIND vertexColorLocation";*/
//
//    while (!glfwWindowShouldClose(window))
//    {
//        handleInput(window);
//        glClear(GL_COLOR_BUFFER_BIT);
//       // float time = glfwGetTime();
//       /* float greenValue = (sin(time) / 2.0f) + 0.5f;
//        glUniform4f(vertexColorLocation, 0, greenValue, 0, 1.0f);*/
//        glUseProgram(shaderProgram);
//        glBindVertexArray(VAO);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    return 0;
//}
//
