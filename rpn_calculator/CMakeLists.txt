cmake_minimum_required(VERSION 3.20)
project(RPN_Calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем директории с исходными файлами
include_directories(include)

# Добавляем основной исполняемый файл со всеми исходниками
add_executable(rpn_calculator
    src/main.cpp
    src/rpn.cpp
)

# Включаем систему тестирования
enable_testing()

# Добавляем тесты напрямую (без поддиректории)
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_rpn.cpp)
    # Подключаем Google Test
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)

    # Добавляем тестовый исполняемый файл
    add_executable(rpn_tests tests/test_rpn.cpp src/rpn.cpp)

    # Линкуем только с gtest
    target_link_libraries(rpn_tests PRIVATE gtest_main)

    target_include_directories(rpn_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

    add_test(NAME rpn_tests COMMAND rpn_tests)
endif()
