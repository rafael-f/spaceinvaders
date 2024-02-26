#pragma once
#include <vector>
#include "InputHandler.h"
#include "UIPanel.h"
#include "ScreenManagerRemoteControl.h"
#include <GLFW/glfw3.h>

class InputHandler;

class Screen
{
private:
	std::vector<std::shared_ptr<InputHandler>> m_InputHandlers;
	std::vector<std::unique_ptr<UIPanel>> m_Panels;

protected:
	void addPanel(std::unique_ptr<UIPanel> p, ScreenManagerRemoteControl* smrc, std::shared_ptr<InputHandler> ih);

public:
	virtual void initialise();
	void virtual update(float fps);
	void virtual draw(GLFWwindow& window);
	void handleInput(GLFWwindow& window);

	virtual ~Screen() = default;
	//View m_View;
};
