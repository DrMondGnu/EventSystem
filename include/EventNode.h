//
// Created by MondGnu on 4/25/2024.
//

#ifndef EVENTSYSTEM_EVENTNODE_H
#define EVENTSYSTEM_EVENTNODE_H

#include <set>
#include "Queue.h"
#include "Event.h"





class EventNode {
public:
    /**
     * dispatch event
     * @param event
     */
    virtual void Dispatch(Event& event);

    /**
     * adds node to this node and removes it from old parent
     * @param node node to add
     */
    void AddNode(EventNode* node);

    /**
     * removes node from this and sets it parent to null
     * @param node node to remove
     */
    void RemoveNode(EventNode* node);

    bool HasNode(EventNode* node);
protected:
    EventNode* parent = nullptr;
    std::set<EventNode*> children;
};






#endif //EVENTSYSTEM_EVENTNODE_H
