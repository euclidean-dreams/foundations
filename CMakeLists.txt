cmake_minimum_required(VERSION 3.13)
project(impresario-utils VERSION 0.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wno-dev)

include(lib/cmake-utils/dependency-integrator.cmake)
integrate_cmake_dependency(
        NAME impresario-serialization
        GIT_URL git@github.com:impresario-systems/impresario-serialization.git
        GIT_TAG origin/dev
)

SET(YAML_CPP_BUILD_TESTS OFF)
SET(YAML_CPP_INSTALL OFF)
SET(YAML_MSVC_SHARED_RT OFF)
SET(YAML_CPP_BUILD_TOOLS OFF)
SET(YAML_CPP_BUILD_CONTRIB OFF)
integrate_cmake_dependency(
        NAME yaml
        GIT_URL git@github.com:jbeder/yaml-cpp.git
        GIT_TAG 9a3624205e8774953ef18f57067b3426c1c5ada6
)
integrate_cmake_dependency(
        NAME spdlog
        GIT_URL git@github.com:gabime/spdlog.git
        GIT_TAG eb3220622e73a4889eee355ffa37972b3cac3df5
)

set(
        SOURCE_FILES
        include/ImpresarioUtils.h

        src/Config.cpp src/Config.h
        src/Bootstrapper.cpp src/Bootstrapper.h

        src/NonCopyable.h
        src/Time.cpp src/Time.h

        src/RandomNumberGenerator.cpp src/RandomNumberGenerator.h

        src/network/NetworkSocket.cpp src/network/NetworkSocket.h
        src/network/Parcel.cpp src/network/Parcel.h
        src/network/Unwrap.cpp src/network/Unwrap.h

        src/circlet/Circlet.cpp src/circlet/Circlet.h
        src/circlet/TickingCirculable.h
        src/circlet/Circulable.h

        src/arbiter/Arbiter.h
        src/arbiter/BufferArbiter.h
        src/Macros.h
        src/Timer.cpp src/Timer.h
        src/percipient/VolitiaPercipient.cpp src/percipient/VolitiaPercipient.h)

add_library(impresario-utils STATIC ${SOURCE_FILES})
target_include_directories(impresario-utils PUBLIC include)

target_link_libraries(impresario-utils PUBLIC zmq)
target_link_libraries(impresario-utils PUBLIC pthread)
target_link_libraries(impresario-utils PUBLIC yaml-cpp)
target_link_libraries(impresario-utils PUBLIC spdlog::spdlog)
target_link_libraries(impresario-utils PUBLIC impresario-serialization)
