//
// Created by MondGnu on 4/27/2024.
//

#include "../include/FilteredEventNode.h"

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
namespace Mond::EventSystem {
#endif


FilteredEventNode::FilteredEventNode(FilteredEventNode::Filter &filter) : filter(filter) {}

void FilteredEventNode::Dispatch(Event &event)
{
    if(filter(event))
        EventNode::Dispatch(event);
}

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
}
#endif