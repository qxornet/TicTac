cmake_minimum_required(VERSION 3.0.0)
project(TicTac VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./Release)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES client.cpp
            core.cpp
            main.cpp)

set(HEADERS client.hpp
            core.hpp)

add_executable(TicTac ${SOURCES} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
