//
// Created by MondGnu on 4/27/2024.
//

#ifndef EVENTSYSTEM_EVENTLISTENER_H
#define EVENTSYSTEM_EVENTLISTENER_H

#include <vector>
#include "Event.h"
#include "EventHandler.h"

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
namespace Mond::EventSystem {
#endif


/**
 * EventListener interface
 */
class EventListener : public EventHandler<Event> {
};

/**
 * default event lister
 * you can attach EventHandlers to it which will be called when the listener is fired
 * @tparam T event type
 */
template <typename T>
requires IsEvent<T>
class DefaultEventListener : public EventListener {
public:

    void HandleEvent(const Event &event) override
    {
        if (typeid(T) == typeid(event))
            callHandlers((const T&)event);
    }
    /**
     * add handler
     * @param handler handler to add
     */
    void AddHandler(EventHandler<T>* handler) {
        handlers.push_back(handler);
    }
    /**
     * remove handler
     * @param handler handler to remove
     */
    void RemoveHandler(EventHandler<T>* handler) {
        handlers.erase(std::remove(handlers.begin(), handlers.end(), handler), handlers.end());
    }

protected:
    /*+
     * calls all attached handlers
     */
    void callHandlers(const T& event) {
        for (auto &item: handlers) {
            item->operator()(event);
        }
    }

    std::vector<EventHandler<T>*> handlers;
};

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
}
#endif

#endif //EVENTSYSTEM_EVENTLISTENER_H
