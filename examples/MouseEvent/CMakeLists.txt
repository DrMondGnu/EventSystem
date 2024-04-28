cmake_minimum_required(VERSION 3.27)

add_executable(MouseClickExample
        MouseEventExample.cpp
)

target_link_libraries(MouseClickExample PRIVATE EventSystem)
