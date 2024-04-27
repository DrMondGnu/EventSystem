//
// Created by MondGnu on 4/25/2024.
//

#ifndef EVENTSYSTEM_EVENTNODE_H
#define EVENTSYSTEM_EVENTNODE_H

#include <set>
#include <vector>
#include "Queue.h"
#include "Event.h"
#include "EventListener.h"

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

    /**
     * adds listener to this node
     * @param listener listener to add
     */
    void AddListener(EventListener* listener);

    /**
     * removes listener from this node
     * @param listener listener to remove
     */
    void RemoveListener(EventListener* listener);

    bool HasNode(EventNode* node);
protected:
    EventNode* parent = nullptr;
    std::set<EventNode*> children;
    std::vector<EventListener*> listeners;
};






#endif //EVENTSYSTEM_EVENTNODE_H
