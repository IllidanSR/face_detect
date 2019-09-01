cmake_minimum_required(VERSION 3.10)

project(application)

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_DEBUG_LIBS         OFF)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.67 REQUIRED COMPONENTS system filesystem)
include_directories(${Boost_INCLUDE_DIRS})

SET(SOURCE
        application.hpp
        application.cpp)

add_library(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} INTERFACE .)

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} image_processing)