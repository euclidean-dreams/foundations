cmake_minimum_required(VERSION 3.13)
project(impresario-utils)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)

set(
        SOURCE_FILES
        src/Utils.h
        src/NonCopyable.h
        src/NetworkSocket.cpp src/NetworkSocket.h
)

add_library(impresario-utils STATIC ${SOURCE_FILES})
target_link_libraries(impresario-utils LINK_PUBLIC zmq)
