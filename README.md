# Event System

An easy to use event system from the Mond namespace

## Install

### Include with cmake project

Clone repository or add as a submodule to an existing git repository

```console
$ git clone https://github.com/DrMondGnu/EventSystem.git
```

Next in your CMakeLists.txt

```cmake
add_subdirectory(<path-to-event-system>)
target_link_library(<your-target> PUBLIC EventSystem)
```

Done!

### Build with cmake

Build for manual linking

```console
$ git clone https://github.com/DrMondGnu/EventSystem.git
$ cd EventSystem && mkdir build && cd build
$ cmake ../ && cmake --build
```

## Platforms

- Windows

## Features

- ID event system

- modern C++23

## Usage

Simple example on how to implement an **MouseClickEvent**

#### MouseClickEvent

```cpp
#include <Event.h>

enum MouseClickType {
    // I recommend to leave 0 for unchecked Events or typeless Events
    MouseLeftClick = 1,
    MouseRightClick = 2,
    MouseMiddleClick = 3,
};

class MouseClickEvent : public Event {
public:
    explicit MouseClickEvent(MouseClickType type) : 
                                    Event((EventType)type) {}
    const MouseClickType& GetClickType() const {return type;}
protected:
    MouseClickType type;
};
```

Now you can implement a handler for such an event

#### MouseClickHandler

```cpp
#include <iostream>
#include <EventHandler.h>

#include "MouseClickEvent.h"

class TestHandler : public EventHandler<MouseClickEvent> {
public:
    void HandleEvent(const MouseClickEvent& event) override {
        std::cout << "Received MouseClickEvent: " << event.GetType();
    }
};
```

Now you could start to dispatch events to this Handler or you can utilize the **EventNodes**.

```cpp
#include <EventNode.h>
#include "TestHandler.h"


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
```

The console output will look like this:

```console
$ Received MouseClickEvent: 1
```


