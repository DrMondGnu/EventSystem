//
// Created by MondGnu on 4/27/2024.
//
#include "../include/Event.h"

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
namespace Mond::EventSystem {
#endif

Event::~Event() = default;

Event::Event(EventType type) : type(type) {}

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
}
#endif