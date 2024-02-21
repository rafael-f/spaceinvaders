#pragma once
#include <string>

class Shader
{
public:
	Shader(unsigned int type, const std::string& filepath);
	~Shader();

	inline unsigned int GetID() const{ return m_RendererID; }

private:
	unsigned int m_RendererID;
	std::string m_FilePath;
	unsigned int m_Type;

	std::string ReadFile();

	bool CompileShader();
};
