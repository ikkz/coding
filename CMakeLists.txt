cmake_minimum_required(VERSION 3.20)
project(coding)

set(CMAKE_CXX_STANDARD 17)
enable_testing()

include_directories("lib")

aux_source_directory(. SRCS)

foreach(SRC ${SRCS})
    string(REPLACE "./" "" TARGET ${SRC})
    string(REPLACE ".cpp" "" TARGET ${TARGET})
    add_executable(${TARGET} ${SRC})
    add_test(NAME ${TARGET} COMMAND ${TARGET})
endforeach()

