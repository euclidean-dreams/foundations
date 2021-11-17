cmake_minimum_required(VERSION 3.13)
project(impresario-utils VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(lib/cmake-utils/dependency-integrator.cmake)
integrate_cmake_dependency(
        NAME impresario-serialization
        GIT_URL git@github.com:impresario-systems/impresario-serialization.git
        GIT_TAG origin/dev
)

set(
        SOURCE_FILES
        include/ImpresarioUtils.h

        src/NonCopyable.h
        src/Time.cpp src/Time.h

        src/RandomNumberGenerator.cpp src/RandomNumberGenerator.h

        src/NetworkProxy.cpp src/NetworkProxy.h
        src/NetworkSocket.cpp src/NetworkSocket.h

        src/SerializedData.cpp src/SerializedData.h

        src/Packet.cpp src/Packet.h
        src/PacketCollection.cpp src/PacketCollection.h
        src/PacketReceiver.cpp src/PacketReceiver.h
        src/InvalidDeserializationException.h

        src/Point.cpp src/Point.h
        src/Circlet.cpp src/Circlet.h
        src/Circulable.h
)

add_library(impresario-utils STATIC ${SOURCE_FILES})
target_include_directories(impresario-utils PUBLIC include)

find_package(cppzmq)
target_link_libraries(impresario-utils PRIVATE cppzmq)
target_link_libraries(impresario-utils PUBLIC impresario-serialization)
target_link_libraries(impresario-utils PUBLIC pthread)
