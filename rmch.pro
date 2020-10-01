HEADERS = interface/rmch_interface.hpp qt/main_window.hpp
SOURCES = main.cpp interface/rmch_interface.cpp
QMAKE_LFLAGS += -no-pie
QT += quickcontrols2
QT += widgets
TARGET = "Remove MC Headers"