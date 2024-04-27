//
// Created by MondGnu on 4/25/2024.
//

#ifndef EVENTSYSTEM_EVENTHANDLER_H
#define EVENTSYSTEM_EVENTHANDLER_H

#include "Event.h"

template <typename T>
requires IsEvent<T>
class EventHandler {
public:
    virtual void HandleEvent(const T& e) = 0;
};


#endif //EVENTSYSTEM_EVENTHANDLER_H
