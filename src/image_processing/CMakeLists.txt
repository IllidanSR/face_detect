cmake_minimum_required(VERSION 3.10)
project(image_processing)

find_package(OpenCV REQUIRED)

SET(SOURCE
        image_processing.hpp
        image_processing.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE})
target_include_directories(${PROJECT_NAME} INTERFACE .)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} face_detect)