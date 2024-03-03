#include "Sprite.h"
#include "VertexBufferLayout.h"
#include <glm/gtc/matrix_transform.hpp>

Sprite::Sprite()
{
	m_Shader.AddShader(GL_VERTEX_SHADER, "VertexShader.hlsl");
	m_Shader.AddShader(GL_FRAGMENT_SHADER, "PixelShader.hlsl");
	m_Shader.CreateShader();

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	m_IndexBuffer = IndexBuffer(indices, 6);
}

void Sprite::setTexture(const Texture& texture)
{
    m_Texture = texture;
}

Texture* Sprite::getTexture()
{
    return &m_Texture;
}

void Sprite::setScale(float x, float y)
{
    m_Scale.x = x;
    m_Scale.y = y;
}

void Sprite::setColor(const Color& color)
{
    m_Color = color;
}

void Sprite::setPosition(Vector2f position)
{
    m_Position = position;
}

void Sprite::Draw(const Renderer& renderer)
{
    // TODO remove opengl learning
    float positions[] =
    {
        -0.5f, -0.5f, 0.0f, 0.0f,
         0.5f, -0.5f, 1.0f, 0.0f,
         0.5f,  0.5f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 1.0f
    };

    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao));

    VertexArray(va);
    VertexBuffer vb(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);
    va.AddBuffer(vb, layout);

    glm::mat4 proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);

    m_Shader.Bind();
    m_Shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
    m_Shader.SetUniformMat4f("u_MVP", proj);

    //Texture texture("graphics/background.png");
    int textureSlot = 0;
    m_Texture.Bind(textureSlot);
    m_Shader.SetUniform1i("u_Texture", textureSlot);

    va.Unbind();
    m_Shader.Unbind();
    vb.Unbind();
    m_IndexBuffer.Unbind();

    renderer.Draw(va, m_IndexBuffer, m_Shader);
}