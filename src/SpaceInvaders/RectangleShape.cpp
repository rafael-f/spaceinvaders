#include "RectangleShape.h"
#include "VertexBufferLayout.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Texture.h"

RectangleShape::RectangleShape()
{
    float vertices[] = {
        // pos
        0.0f, 1.0f,
        1.0f, 0.0f,
        0.0f, 0.0f,

        0.0f, 1.0f,
        1.0f, 1.0f,
        1.0f, 0.0f,
    };

    VertexBuffer vb = VertexBuffer(vertices, sizeof(vertices));

    VertexBufferLayout layout;
    layout.Push<float>(2);

    m_VertexArray.AddBuffer(vb, layout);

    vb.Unbind();
    m_VertexArray.Unbind();
}

void RectangleShape::setPosition(Vector2f position)
{
    m_Position = position;
}

void RectangleShape::setFillColor(const Color& color)
{
    m_Color = color;
}

void RectangleShape::setSize(Vector2f size)
{
    m_Size = size;
}

void RectangleShape::Draw()
{
    m_Shader.Bind();

    glm::mat4 model = glm::mat4(1.0f);

    model = glm::translate(model, glm::vec3(m_Position.x, m_Position.y, 0.0f));

    model = glm::scale(model, glm::vec3(m_Size.x, m_Size.y, 1.0f));

    m_Shader.SetUniformMat4f("model", model);

    m_Shader.SetUniform4f("spriteColor", m_Color.getRGBA().x / 255.0f, m_Color.getRGBA().y / 255.0f, m_Color.getRGBA().z / 255.0f, m_Color.getRGBA().w / 255.0f);

    m_VertexArray.Bind();
    glDrawArrays(GL_TRIANGLES, 0, 6);
    m_VertexArray.Unbind();
}
