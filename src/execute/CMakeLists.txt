cmake_minimum_required(VERSION 3.10)
project(execute)
set(CMAKE_CXX_STANDARD 11)

find_package(Boost 1.67 REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

#SET(FIND_FACE_LIB face_detect)
SET(SOURCE
        main.cpp
        application.cpp
        application.hpp)

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(${PROJECT_NAME} image_processing)