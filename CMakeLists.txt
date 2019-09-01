cmake_minimum_required(VERSION 3.10)
project(fdetectlib VERSION 1.0.1 DESCRIPTION "face_detect_lib")

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
#SET OUTPUT DIRS
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(OpenCV 3.4 REQUIRED)

find_package(Boost 1.65 REQUIRED COMPONENTS filesystem system)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

find_package(Boost 1.67 REQUIRED)
include_directories(${Boost})

SET(SOURCE
        include/library.h
        src/library.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION 1)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/library.h)

target_include_directories(${PROJECT_NAME} PRIVATE .)

include(GNUInstallDirs)



target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
install(TARGETS ${PROJECT_NAME}
        COMPONENT fdetect
        RUNTIME DESTINATION "/home/"
        LIBRARY DESTINATION "/home/"
        DESTINATION "/home/"
        )

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK")
include(CPack)