#pragma once
#include <iostream>
#include "Shader.h"
#include <vector>
#include <unordered_map>

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();

	void AddShader(unsigned int type, const std::string& filename);

	void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

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