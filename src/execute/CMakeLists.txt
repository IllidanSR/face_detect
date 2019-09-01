cmake_minimum_required(VERSION 3.10)
project(execute)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_DEBUG_LIBS         OFF)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.67 REQUIRED COMPONENTS system filesystem)
include_directories(${Boost_INCLUDE_DIRS})

#SET(FIND_FACE_LIB face_detect)
SET(SOURCE
        main.cpp
        application.cpp
        application.hpp)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} image_processing)
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
