#pragma once
#include "Renderer.h"
#include "Vector2i.h"

class Texture
{
public:
	Texture() = default; // todo shouldn't be needed

	explicit Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0);
	void Unbind();

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

	Vector2i getSize();

private:
	unsigned int m_RendererID = 0;
	
	std::string m_FilePath;

	unsigned char* m_LocalBuffer = nullptr;

	int m_Width = 0;
	int m_Height = 0;
	int m_BPP = 0;
};
