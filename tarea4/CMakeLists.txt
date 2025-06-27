cmake_minimum_required(VERSION 3.5)

# Set the project name
project(esp32-freertos-timer)

# Include the ESP-IDF build system
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# Specify the source files
set(SOURCES
    src/main.c
    src/freertos_timer.c
)

# Specify the include directories
include_directories(include)

# Add the executable target
idf_component_register(SRCS ${SOURCES}
                       INCLUDE_DIRS include)