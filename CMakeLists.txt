cmake_minimum_required(VERSION 3.18.4)
project(CMakeTutorial
    VERSION 1.0
    DESCRIPTION "Particle"
    LANGUAGES CXX)

file(GLOB MAIN "src/Sol10.cpp")

add_executable(executable ${MAIN})