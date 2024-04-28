cmake_minimum_required(VERSION 3.27)

option(MOND_EVENT_SYSTEM_EXAMPLES_MOUSE_CLICK_COMPILE "Enable if mouse click event example should be compiled" ON)

if (MOND_EVENT_SYSTEM_EXAMPLES_MOUSE_CLICK_COMPILE)
    add_subdirectory(MouseEvent)
endif (MOND_EVENT_SYSTEM_EXAMPLES_MOUSE_CLICK_COMPILE)