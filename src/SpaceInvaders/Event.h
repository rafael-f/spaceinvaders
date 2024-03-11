#pragma once
#include "KeyEvent.h"
#include "Vector2i.h"

class Event
{
public:
    enum EventType
    {
        KeyPressed,
        KeyReleased,
        MouseButtonReleased
    };

    EventType type{};

    KeyEvent key;

    Vector2i mousePosition;
};
