//
// Created by MondGnu on 4/27/2024.
//

#include "../include/FilteredEventNode.h"

FilteredEventNode::FilteredEventNode(FilteredEventNode::Filter &filter) : filter(filter) {}

void FilteredEventNode::Dispatch(Event &event)
{
    if(filter(event))
        EventNode::Dispatch(event);
}
