#include "View.h"
#include <gl/glew.h>
#include <Windows.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderManager.h"

void View::setSize(Vector2f size)
{
    m_Size = size;
}

void View::setSize(float x, float y)
{
    m_Size.x = x;
    m_Size.y = y;
}

void View::setCenter(float x, float y)
{
    m_Center.x = x;
    m_Center.y = y;
}

void View::setCenter(Vector2f center)
{
    m_Center = center;
}

void View::setViewport(const FloatRect& viewport)
{
    m_Viewport.setValues(viewport.getPosition().x, viewport.getPosition().y, viewport.getSize().x, viewport.getSize().y);
}

Vector2f View::getSize() const
{
    return m_Size;
}

void View::setActive()
{
    //float x = GetSystemMetrics(SM_CXSCREEN);
    //float y = GetSystemMetrics(SM_CYSCREEN);

    //float xf = m_Viewport.getPosition().x * x;
    //float yf = m_Viewport.getPosition().y * y;
    //float wf = m_Viewport.getSize().x * x;
    //float hf = m_Viewport.getSize().y * y;

    //glViewport(xf, yf, wf, hf);

    //glm::mat4 projection = glm::ortho(xf, xf+wf, yf+hf, yf, -1.0f, 1.0f);
    //glm::mat4 projection = glm::ortho(100.0f, 2000.0f, 2000.0f, 1000.0f, -1.0f, 1.0f);
    //glm::mat4 projection = glm::ortho(xf, x, y, yf, -1.0f, 1.0f);

    /*ShaderProgram spriteShader = ShaderManager::GetShader("sprite");
    spriteShader.Bind();
    spriteShader.SetUniformMat4f("projection", projection);
    spriteShader.Unbind();

    ShaderProgram buttonShader = ShaderManager::GetShader("button");
    buttonShader.Bind();
    buttonShader.SetUniformMat4f("projection", projection);
    buttonShader.Unbind();*/
}
