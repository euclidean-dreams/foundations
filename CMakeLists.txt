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

        src/network/NetworkProxy.cpp src/network/NetworkProxy.h
        src/network/NetworkSocket.cpp src/network/NetworkSocket.h

        src/network/SerializedData.cpp src/network/SerializedData.h

        src/parcel/Parcel.cpp src/parcel/Parcel.h
        src/parcel/ParcelCollection.cpp src/parcel/ParcelCollection.h
        src/parcel/ParcelReceiver.cpp src/parcel/ParcelReceiver.h
        src/network/InvalidDeserializationException.h

        src/Point.cpp src/Point.h

        src/circlet/Circlet.cpp src/circlet/Circlet.h
        src/circlet/Circulable.h

        src/arbiter/Arbiter.h
        src/arbiter/BufferArbiter.h
        src/Coordinate.cpp src/Coordinate.h)

add_library(impresario-utils STATIC ${SOURCE_FILES})
target_include_directories(impresario-utils PRIVATE src)
target_include_directories(impresario-utils PUBLIC include)

find_package(cppzmq)
target_link_libraries(impresario-utils PRIVATE cppzmq)
target_link_libraries(impresario-utils PRIVATE pthread)
target_link_libraries(impresario-utils PUBLIC impresario-serialization)
