cmake_minimum_required(VERSION 3.22)
project(coding)

set(CMAKE_CXX_STANDARD 17)

include_directories("lib")

aux_source_directory(. SRCS)

foreach(SRC ${SRCS})
    string(REPLACE "./" "" TARGET ${SRC})
    string(REPLACE ".cpp" "" TARGET ${TARGET})
    add_executable(${TARGET} ${SRC} 2_2_11.cpp)
endforeach()

