//
// Created by MondGnu on 4/25/2024.
//
#include "../include/EventNode.h"

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
namespace Mond::EventSystem {
#endif


void EventNode::Dispatch(Event &event)
{
    for (const auto &item: listeners) {
        item->HandleEvent(event);
    }
    for (auto &item: children) {
        item->Dispatch(event);
    }
}

void EventNode::AddNode(EventNode *node)
{
    if(node == this)
        return;
    if(node) {
        if(node->parent)
            node->parent->RemoveNode(node);
        children.insert(node);
        node->parent = this;
    }
}

void EventNode::RemoveNode(EventNode *node)
{
    if (node == this)
        return;
    if(children.erase(node) > 0) {
        if(node->parent == this) {
            node->parent = nullptr;
        }
    }
}

bool EventNode::HasNode(EventNode *node)
{
    return children.contains(node);
}

void EventNode::AddListener(EventListener *listener)
{
    listeners.push_back(listener);
}

void EventNode::RemoveListener(EventListener *listener)
{
    listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
}
#endif