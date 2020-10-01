cmake_minimum_required(VERSION 3.17)
project(RemoveMCHeaders)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Core Quick QuickControls2 REQUIRED)

add_executable(RemoveMCHeaders
        main.cpp
        qt/main_window.hpp
        interface/rmch_interface.hpp interface/rmch_interface.cpp)

target_link_libraries(RemoveMCHeaders Qt5::Widgets Qt5::Core Qt5::Quick Qt5::QuickControls2)