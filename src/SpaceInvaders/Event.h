#pragma once

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
};
