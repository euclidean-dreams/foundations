cmake_minimum_required(VERSION 3.13)
project(impresario-utils VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(
        SOURCE_FILES
        include/mixin/NonCopyable.h

        src/utils/RandomNumberGenerator.cpp include/utils/RandomNumberGenerator.h
        src/utils/Time.cpp include/utils/Time.h

        src/network/Proxy.cpp include/network/Proxy.h
        src/network/Socket.cpp include/network/Socket.h
)

add_library(impresario-utils STATIC ${SOURCE_FILES})
target_include_directories(impresario-utils PUBLIC include)

find_package(cppzmq)
target_link_libraries(impresario-utils PRIVATE cppzmq)
