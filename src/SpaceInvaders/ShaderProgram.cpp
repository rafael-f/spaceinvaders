#include "ShaderProgram.h"
#include "Renderer.h"
#include <iostream>

ShaderProgram::ShaderProgram()
{
	GLCall(m_RendererID = glCreateProgram());
}

ShaderProgram::~ShaderProgram()
{
	//GLCall(glDeleteProgram(m_RendererID)); todo
}

void ShaderProgram::SetUniform1i(const std::string& name, int value)
{
	GLCall(glUniform1i(GetUniformLocation(name), value));
}

void ShaderProgram::SetUniform3f(const std::string& name, float v0, float v1, float v2)
{
	GLCall(glUniform3f(GetUniformLocation(name), v0, v1, v2));
}

void ShaderProgram::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void ShaderProgram::SetUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	GLCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}

int ShaderProgram::GetUniformLocation(const std::string& name)
{
	if (m_Locations.find(name) != m_Locations.end())
	{
		return m_Locations[name];
	}
	else
	{
		GLCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));

		if (location == -1)
		{
			std::cout << "ERROR, ShaderProgram::GetUniformLocation could not find " << name << std::endl;
		}

		m_Locations[name] = location;

		return location;
	}
}

void ShaderProgram::Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource)
{
	unsigned int sVertex;
	unsigned int sFragment;
	unsigned int gShader;

	// vertex Shader
	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexSource, nullptr);
	glCompileShader(sVertex);
	checkCompileErrors(sVertex, "VERTEX");

	// fragment Shader
	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, nullptr);
	glCompileShader(sFragment);
	checkCompileErrors(sFragment, "FRAGMENT");

	// if geometry shader source code is given, also compile geometry shader
	if (geometrySource != nullptr)
	{
		gShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(gShader, 1, &geometrySource, nullptr);
		glCompileShader(gShader);
		checkCompileErrors(gShader, "GEOMETRY");
	}

	// shader program
	m_RendererID = glCreateProgram();
	glAttachShader(m_RendererID, sVertex);
	glAttachShader(m_RendererID, sFragment);
	if (geometrySource != nullptr)
		glAttachShader(m_RendererID, gShader);
	glLinkProgram(m_RendererID);
	checkCompileErrors(m_RendererID, "PROGRAM");

	// delete the shaders as they're linked into our program now and no longer necessary
	glDeleteShader(sVertex);
	glDeleteShader(sFragment);
	if (geometrySource != nullptr)
		glDeleteShader(gShader);
}

void ShaderProgram::Bind() const
{
	GLCall(glUseProgram(m_RendererID));
}

void ShaderProgram::Unbind() const
{
	GLCall(glUseProgram(0));
}

void ShaderProgram::checkCompileErrors(unsigned int object, const std::string& type) const
{
	int success;
	char infoLog[1024];

	if (type != "PROGRAM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
	else
	{
		glGetProgramiv(object, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
				<< infoLog << "\n -- --------------------------------------------------- -- "
				<< std::endl;
		}
	}
}
