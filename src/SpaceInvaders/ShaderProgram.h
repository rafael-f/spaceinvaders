#pragma once
#include "Shader.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <glm/glm.hpp>

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

	void AddShader(unsigned int type, const std::string& filename);

	void SetUniform1i(const std::string& name, int value);
	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void SetUniformMat4f(const std::string& name, const glm::mat4& matrix);

	int GetUniformLocation(const std::string& name);

	void CreateShader();

	void Bind() const;
	void Unbind() const;

	inline unsigned int GetID() const { return m_RendererID; }

private:
	std::vector<Shader> m_Shaders;

	unsigned int m_RendererID;

	std::unordered_map<std::string, int> m_Locations;
};
