//
// Created by MondGnu on 4/25/2024.
//
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include <string>

#include "Event.h"
#include "EventHandler.h"
#include "EventNode.h"
#include "EventListener.h"

#ifdef MOND_EVENT_SYSTEM_ENABLE_NAMESPACE
using namespace Mond::EventSystem;
#endif

class TestEvent : public Event {
public:
    explicit TestEvent() : Event(1) {}

    std::string Name() const {
        return "Test Event";
    }
};

class TestEvent2 : public Event {
public:
    explicit TestEvent2() : Event(1) {}

    std::string Name() const {
        return "Test Event";
    }
};

class TestEventHandler : public EventHandler<TestEvent>{
public:
    bool Handled = false;
    void HandleEvent(const TestEvent &t) override
    {
        Handled = true;
    }
};

class TestEventListener : public EventListener {
public:
    bool Handled = false;
    void HandleEvent(const Event &e) override
    {
        if(e.GetType() != 1)
            return;
        Handled = true;
    }
};

TEST_CASE("EventHandlerTest") {
    TestEventHandler handler;
    TestEvent event;

    handler.HandleEvent(event);
    CHECK(handler.Handled);
}

TEST_CASE("EventNodeTest") {
    EventNode node1;
    EventNode node2;

    node1.AddNode(&node2);

    CHECK(node1.HasNode(&node2));
}


TEST_CASE("EventListenerTest") {
    EventNode node;
    TestEventListener listener;
    TestEvent event;

    node.AddListener(&listener);
    node.Dispatch(event);



    CHECK(listener.Handled);
}

TEST_CASE("DefaultEventListenerTest") {
    EventNode node;
    DefaultEventListener<TestEvent> listener;
    TestEventHandler handler;

    TestEvent testEvent;
    TestEvent2 testEvent2;

    node.AddListener(&listener);
    listener.AddHandler(&handler);

    node.Dispatch(testEvent2);
    CHECK_FALSE(handler.Handled);

    node.Dispatch(testEvent);
    CHECK(handler.Handled);
}
