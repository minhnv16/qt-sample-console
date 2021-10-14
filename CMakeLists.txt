cmake_minimum_required(VERSION 3.5)

set(PROJ_NAME sample-console-nonqt)
project(${PROJ_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_executable(${PROJ_NAME} main.cpp)
target_link_libraries(
    ${PROJ_NAME}
    ${CMAKE_THREAD_LIBS_INIT}
    )
