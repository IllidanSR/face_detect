cmake_minimum_required(VERSION 3.10)
project(face_detect)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

find_package(Boost 1.65 REQUIRED COMPONENTS filesystem system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

SET(SOURCE
        face_detect.hpp
        face_detect.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_include_directories(${PROJECT_NAME} INTERFACE .)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})