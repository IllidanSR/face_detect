cmake_minimum_required(VERSION 3.10)
project(face_detection)

set(CMAKE_CXX_STANDARD 11)

###############################################################################

#SET BUILD DIR
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
#SET OUTPUT DIRS
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

###############################################################################

#SET INSTALL PARS
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(FACE_DETECT_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(FACE_DETECT_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(FACE_DETECT_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

message(INSTALL_INCLUDE_DIR : ${FACE_DETECT_INSTALL_INCLUDE_DIR})
message(INSTALL_BIN_DIR : ${FACE_DETECT_INSTALL_BIN_DIR})
message(INSTALL_LIB_DIR : ${FACE_DETECT_INSTALL_LIB_DIR})

###############################################################################

SET(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})

add_subdirectory(src)

###############################################################################
#ENABLE TESTS
enable_testing()
###############################################################################
#START TESTS IF MAY
if(BUILD_TESTING)
    add_subdirectory(src/tests)
endif()
