#pragma once
#ifndef SHADER_H
#define SHADER_H

#include<glad/glad.h>
#include<glm/glm.hpp>

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>

class Shader
{

public:
	//the program ID
	unsigned int ID;

	//constructor read and built the shader
	Shader(const char* vertexPath, const char* fragmentPath);

	//use or activate shader
	void use();
	//utility uniform function
	void setBool(const std::string &name,bool value) const;
	void setInt(const std::string &name,int value) const;
	void setFloat(const std::string &name,float value) const;
	void setMat4(const std::string& name, glm::mat4 mat) const;
	void setTexture(const std::string& name, unsigned int texture) const;
	void setVec3(const std::string& name, glm::vec3 vec) const;

};

#endif // !SHADER_H

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	//reciveing vertex/fragment shader code and file
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;
	//ensure ifstream object can throw exception
	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		//opening Shader files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		std::stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		//close Shader File
		vShaderFile.close();
		fShaderFile.close();

		//converting stream to string
		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (const std::exception&)
	{
		std::cout << "ERROR: SHADER::FILE_NOT_SUCCESSFULY_READ "<<std::endl;
	}
	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	unsigned int vertex, fragment;
	int success;
	char infoLog[512];

	//Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		std::cout << "ERROR: VERTEX SHADER: COMPILATION_ERROR " << infoLog << std::endl;
	}
	//Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		std::cout << "ERROR: FRAGMENT SHADER: COMPILATION_ERROR " << infoLog << std::endl;
	}

	//Shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);

	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR: SHADER PROGRAM: COMPILATION_ERROR " << infoLog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);


}
inline void Shader::use()
{
	glUseProgram(ID);
}

inline void Shader::setBool(const std::string& name, bool value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()),value);
}

inline void Shader::setInt(const std::string& name, int value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()),value);
}

inline void Shader::setFloat(const std::string& name, float value)const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()),value);
}

inline void Shader::setMat4(const std::string& name, glm::mat4 mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));

}

inline void Shader::setTexture(const std::string& name, unsigned int texture) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), texture);

}

inline void Shader::setVec3(const std::string& name, glm::vec3 vec) const
{

	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(vec));
}
