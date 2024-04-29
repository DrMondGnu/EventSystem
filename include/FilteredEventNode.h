//
// Created by MondGnu on 4/27/2024.
//

#ifndef EVENTSYSTEM_FILTEREDEVENTNODE_H
#define EVENTSYSTEM_FILTEREDEVENTNODE_H

#include <functional>
#include "EventNode.h"

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
namespace Mond::EventSystem {
#endif


class FilteredEventNode : public EventNode {
public:
    using Filter = std::function<bool(const Event&)>;

    explicit FilteredEventNode(Filter &filter);

    void Dispatch(Event &event) override;

protected:
    Filter filter;
};

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
}
#endif

#endif //EVENTSYSTEM_FILTEREDEVENTNODE_H
