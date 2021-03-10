cmake_minimum_required(VERSION 3.13)
project(impresario-utils VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(
        SOURCE_FILES
        include/NonCopyable.h
        src/Time.cpp include/Time.h

        src/RandomNumberGenerator.cpp include/RandomNumberGenerator.h

        src/NetworkProxy.cpp include/NetworkProxy.h
        src/NetworkSocket.cpp include/NetworkSocket.h
)

add_library(impresario-utils STATIC ${SOURCE_FILES})
target_include_directories(impresario-utils PUBLIC include)

find_package(cppzmq)
target_link_libraries(impresario-utils PRIVATE cppzmq)
