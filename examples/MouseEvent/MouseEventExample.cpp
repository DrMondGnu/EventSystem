//
// Created by MondGnu on 4/29/2024.
//

#include <iostream>
#include <Event.h>
#include <EventHandler.h>
#include <EventListener.h>
#include <EventNode.h>

enum MouseClickType {
    // I recommend to leave 0 for unchecked Events or typeless Events
    MouseLeftClick = 1,
    MouseRightClick = 2,
    MouseMiddleClick = 3,
};

class MouseClickEvent : public Event {
public:
    explicit MouseClickEvent(MouseClickType type) :
            Event((EventType) type) {}

    [[nodiscard]] const MouseClickType &GetClickType() const {return type;}
protected:
    MouseClickType type;
};

class TestHandler : public EventHandler<MouseClickEvent> {
public:
    void HandleEvent(const MouseClickEvent& event) override {
        std::cout << "Received MouseClickEvent: " << event.GetType();
    }
};

int main() {
    TestHandler handler; // Create your handler
    DefaultEventListener<MouseClickEvent> listener; // A listener for MouseClick Events
    EventNode node; // The event node

    node.AddListener(&listener); // add the listener to the event node
    // the listener will now listen for any MouseClickEvent
    // MouseClickEvents will be dispatched to the handlers
    listener.AddHandler(&handler); // Add the handler to the listener

    // Now we can send mouse events and our handler will receive it
    MouseClickEvent event(MouseLeftClick);

    node.Dispatch(event); // And finally dispatch the event
    return 0;
}
