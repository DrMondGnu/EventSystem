//
// Created by MondGnu on 4/25/2024.
//

#ifndef EVENTSYSTEM_EVENT_H
#define EVENTSYSTEM_EVENT_H

#include <type_traits>
// TODO: allow customizing evenType size
typedef uint32_t EventType;

class Event {
public:
    explicit Event(EventType type);

    [[nodiscard]] EventType GetType() const {
        return type;
    }
    virtual ~Event() = 0;
private:
    EventType type;
};

template <typename T>
concept IsEvent = std::derived_from<T, Event>;

#endif //EVENTSYSTEM_EVENT_H
