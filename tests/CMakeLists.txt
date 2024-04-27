cmake_minimum_required(VERSION 3.27)


add_executable(EventSystemTests doctest.h
        src/event_system_tests.cpp
)
target_link_libraries(EventSystemTests PRIVATE EventSystem)
