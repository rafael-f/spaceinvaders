#pragma once
#include "KeyEvent.h"

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
};
