//
// Created by MondGnu on 4/25/2024.
//

#ifndef EVENTSYSTEM_EVENT_H
#define EVENTSYSTEM_EVENT_H

#include <concepts>

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
namespace Mond::EventSystem {
#endif


// TODO: allow customizing evenType size
typedef uint32_t EventType;

class Event {
public:
    explicit Event(EventType type);

    [[nodiscard]] EventType GetType() const
    {
        return type;
    }

    virtual ~Event() = 0;

private:
    EventType type;
};

template<typename T>
concept IsEvent = std::derived_from<T, Event>;

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
}
#endif
#endif //EVENTSYSTEM_EVENT_H
