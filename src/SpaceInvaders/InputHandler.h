#pragma once
#include <vector>
#include "Button.h"
#include "Screen.h"
#include "ScreenManagerRemoteControl.h"
#include "Event.h"

class Screen;

class InputHandler
{
private:
	Screen* m_ParentScreen;
	std::vector<std::shared_ptr<Button>> m_Buttons;
	View* m_PointerToUIPanelView;
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;

public:
	virtual ~InputHandler() = default;

	void initialiseInputHandler(ScreenManagerRemoteControl* sw, std::vector<std::shared_ptr<Button>>, View* pointerToUIView, Screen* parentScreen);

	void handleInput(RenderWindow& window, Event& event);

	virtual void handleGamepad();

	virtual void handleKeyPressed(Event& event, RenderWindow& window);

	virtual void handleKeyReleased(Event& event, RenderWindow& window);

	virtual void handleLeftClick(std::string& buttonInteractedWith, RenderWindow& window);

	View* getPointerToUIView();

	ScreenManagerRemoteControl* getPointerToScreenManagerRemoteControl();

	Screen* getmParentScreen();
};
