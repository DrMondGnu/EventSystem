//
// Created by MondGnu on 4/25/2024.
//
#include "../include/EventNode.h"


void EventNode::Dispatch(Event &event)
{
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
