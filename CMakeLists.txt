cmake_minimum_required(VERSION 3.13)
project(impresario-utils VERSION 0.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(
        SOURCE_FILES
        include/Utils.h
        include/NonCopyable.h

        src/NetworkSocket.cpp include/NetworkSocket.h
        src/ParameterReceiver.cpp include/ParameterReceiver.h
)

add_library(impresario-utils STATIC ${SOURCE_FILES})
target_include_directories(impresario-utils PUBLIC include)
target_link_libraries(impresario-utils PRIVATE zmq)
