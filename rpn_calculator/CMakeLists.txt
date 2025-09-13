cmake_minimum_required(VERSION 3.20)
project(Calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_SXX_STANDART 20)
set(CMAKE_SXX_STANDART_REQUIRED ON)

include_directories(include)

add_executable(rpn_calculator src/main.cpp src/rpn.cpp)

set_target_properties(rpn_calculator PROPERTIES CXX_STANDARD_REQUIRED YES CXX_EXTENSIONS NO)

enable_testing()

add_subdirectory(tests)
