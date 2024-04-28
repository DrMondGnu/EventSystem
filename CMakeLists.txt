cmake_minimum_required(VERSION 3.27)
project(EventSystem)

set(CMAKE_CXX_STANDARD 23)

# options
option(MOND_EVENT_SYSTEM_COMPILE_TESTS "Enable if tests should be added to project and compiled" ON)
option(MOND_EVENT_SYSTEM_COMPILE_EXAMPLES "Enable if examples should be added to project and compiled" ON)

add_library(EventSystem STATIC
        include/Event.h
        include/EventHandler.h
        include/EventNode.h
        src/EventNode.cpp
        include/Queue.h
        src/Event.cpp
        src/FilteredEventNode.cpp
        include/FilteredEventNode.h
        include/EventListener.h
)

target_include_directories(EventSystem INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Tests
if(MOND_EVENT_SYSTEM_COMPILE_TESTS)
    add_subdirectory(tests)
endif ()

# Examples
if(MOND_EVENT_SYSTEM_COMPILE_EXAMPLES)
    add_subdirectory(examples)
endif ()