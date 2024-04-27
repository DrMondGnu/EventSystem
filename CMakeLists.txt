cmake_minimum_required(VERSION 3.27)
project(EventSystem)

set(CMAKE_CXX_STANDARD 23)

add_library(EventSystem STATIC
        include/Event.h
        include/EventHandler.h
        include/EventNode.h
        src/EventNode.cpp
        include/Queue.h
        src/Event.cpp
)

target_include_directories(EventSystem INTERFACE include)

add_subdirectory(tests)