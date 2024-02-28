#include "ShaderProgram.h"
#include "Renderer.h"

ShaderProgram::ShaderProgram()
{
	GLCall(m_RendererID = glCreateProgram());
}

ShaderProgram::~ShaderProgram()
{
	GLCall(glDeleteProgram(m_RendererID));
}

// todo maybe read type from shader first line?
void ShaderProgram::AddShader(unsigned int type, const std::string& filename)
{
	//if (m_Shaders.find(filename) == m_Shaders.end())
	//{
	//	m_Shaders.emplace(filename, type, filename);
	//}
	//else
	//{
	//	// todo log or error?
	//}
	Shader shader(type, filename);

	m_Shaders.push_back(shader);

	GLCall(glAttachShader(m_RendererID, shader.GetID()));
}

void ShaderProgram::SetUniform1i(const std::string& name, int value)
{
	GLCall(glUniform1i(GetUniformLocation(name), value));
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
			// todo print error
		}

		m_Locations[name] = location;

		return location;
	}
}

void ShaderProgram::CreateShader()
{
	//for (const auto& shader : m_Shaders)
	//{
	//	GLCall(glAttachShader(m_RendererID, shader.GetID()));
	//}

	GLCall(glLinkProgram(m_RendererID));
	GLCall(glValidateProgram(m_RendererID));

	for (const auto& shader : m_Shaders)
	{
		GLCall(glDeleteShader(shader.GetID()));
	}

	//m_Shaders.clear(); // todo check for leaks
}

void ShaderProgram::Bind() const
{
	GLCall(glUseProgram(m_RendererID));
}

void ShaderProgram::Unbind() const
{
	GLCall(glUseProgram(0));
}
