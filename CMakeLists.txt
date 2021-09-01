cmake_minimum_required(VERSION 3.13)

project(translatortest VERSION 0.1.0)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_executable(test main.cpp)
target_link_libraries(test Qt5::Core Qt5::Widgets)
