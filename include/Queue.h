//
// Created by MondGnu on 4/27/2024.
//

#ifndef EVENTSYSTEM_QUEUE_H
#define EVENTSYSTEM_QUEUE_H

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
namespace Mond::EventSystem {
#endif


template <typename T>
class Queue {
public:
    struct Node {
        Node* next;
        T event;
    };

    Node* PopFront() {
        Node* rt = head;
        head = head->next;
        return rt;
    }

    Node* PushFront(T t) {
        auto* node = new Node(nullptr, t);

        if(!head) {
            head = node;
        } else {
            node->next = head;
            head = node;
        }
        return node;
    }
protected:
    Node* head;
};

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
}
#endif

#endif //EVENTSYSTEM_QUEUE_H
