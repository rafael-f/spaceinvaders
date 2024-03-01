#include "Shader.h"
#include <fstream>
#include "Renderer.h"

Shader::Shader(unsigned int type, const std::string& filepath)
	:m_RendererID(0), m_FilePath(filepath), m_Type(type)
{
	CompileShader();
}

Shader::~Shader()
{
	GLCall(glDeleteShader(m_RendererID));
}

std::string Shader::ReadFile() const
{
	std::ifstream file_stream(m_FilePath);

	if (file_stream.is_open())
	{
		std::string file_content;

		std::string line;
		while (std::getline(file_stream, line)) {
			file_content += line + "\n";
		}

		file_stream.close();

		return file_content;
	}
	else
	{
		return nullptr;
	}
}

bool Shader::CompileShader()
{
	m_RendererID = glCreateShader(m_Type);

	std::string shaderSource = ReadFile();

	const char* src = shaderSource.c_str();
	glShaderSource(m_RendererID, 1, &src, nullptr);
	glCompileShader(m_RendererID);

	int result;
	glGetShaderiv(m_RendererID, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(m_RendererID, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(m_RendererID, length, &length, message);
		// todo print error
		glDeleteShader(m_RendererID);
		return false;
	}

	return true;
}
