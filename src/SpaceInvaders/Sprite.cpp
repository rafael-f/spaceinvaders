#include "Sprite.h"
#include "VertexBufferLayout.h"
#include <glm/gtc/matrix_transform.hpp>

Sprite::Sprite(ShaderProgram& shader, Texture& texture)
    :m_Shader(shader), m_Texture(texture)
{
    float vertices[] = {
        // pos      // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };

    VertexBuffer vb = VertexBuffer(vertices, sizeof(vertices));

    VertexBufferLayout layout;
    layout.Push<float>(4);

    m_VertexArray.AddBuffer(vb, layout);

    vb.Unbind();
    m_VertexArray.Unbind();
}

Texture* Sprite::getTexture()
{
    return &m_Texture;
}

void Sprite::setSize(float x, float y)
{
    m_Size.x = x;
    m_Size.y = y;
}

void Sprite::setColor(const Color& color)
{
    m_Color = color;
}

void Sprite::setPosition(Vector2f position)
{
    m_Position = position;
}

void Sprite::Draw()
{
    m_Shader.Bind();

    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(m_Position.x, m_Position.y, 0.0f));

    model = glm::scale(model, glm::vec3(m_Size.x, m_Size.y, 1.0f));

    m_Shader.SetUniformMat4f("model", model);

    m_Shader.SetUniform3f("spriteColor", m_Color.getRGB().x, m_Color.getRGB().y, m_Color.getRGB().z);

    m_Texture.Bind(0);

    m_VertexArray.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    m_VertexArray.Unbind();
}
