TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

win32{
BOOST_PATH = ../../3rdLibs/boost/boost_1_56_0
BOOST_LIBS = $${BOOST_PATH}/mingw32_4_8_2
BOOST_VER = 1_56

INCLUDEPATH += $${BOOST_PATH}
INCLUDEPATH += ../libs

include(mingw32.pri)
}

SOURCES += main.cpp \
    parser.cpp \
    linux_interfaces_parser.cc

HEADERS += \
    parser.hpp \
    linux_interfaces_parser.h

