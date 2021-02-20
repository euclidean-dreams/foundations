cmake_minimum_required(VERSION 3.13)
project(impresario-utils)
set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(include)

set(
        SOURCE_FILES
        include/Utils.h
        include/NonCopyable.h
        src/NetworkSocket.cpp include/NetworkSocket.h
)

add_library(impresario-utils STATIC ${SOURCE_FILES})
target_include_directories(impresario-utils PUBLIC include)
target_link_libraries(impresario-utils LINK_PUBLIC zmq)
