# Test adding Greenbell static library
cmake_minimum_required(VERSION 3.7.2)
project(Test)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)
set(COMPILE_OPTIONS_C -O2 -Wall)

set(PROJECT_WARNINGS
    -Wall
    -Wextra
    -Wshadow
    -Wnon-virtual-dtor
    -Wcast-align
    -Woverloaded-virtual
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wno-sign-conversion
    -Wnull-dereference
    -Wdouble-promotion
)

set(greenbell_INCLUDE "../greenbell/include" CACHE STRING
    "Greenbell Development Files")

set(greenbell_DIR "../greenbell/build" CACHE STRING
    "Greenbell Library Location")
find_package(greenbell)

add_executable(test
    main.cpp
)
target_link_libraries(test greenbell)
target_compile_options(test PRIVATE ${PROJECT_WARNINGS})
target_include_directories(test
    PUBLIC
        ${greenbell_INCLUDE}
        ${greenbell_DIR}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/..)
