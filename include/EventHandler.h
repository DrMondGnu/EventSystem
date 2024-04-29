//
// Created by MondGnu on 4/25/2024.
//

#ifndef EVENTSYSTEM_EVENTHANDLER_H
#define EVENTSYSTEM_EVENTHANDLER_H

#include "Event.h"

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
namespace Mond::EventSystem {
#endif


template <typename T>
requires IsEvent<T>
class EventHandler {
public:
    virtual void HandleEvent(const T& e) = 0;
    void operator()(const T& event) {
        HandleEvent(event);
    }
};

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
}
#endif

#endif //EVENTSYSTEM_EVENTHANDLER_H
