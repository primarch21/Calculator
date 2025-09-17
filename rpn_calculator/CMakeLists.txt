cmake_minimum_required(VERSION 3.20)
project(RPN_Calculator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Находим библиотеку потоков
find_package(Threads REQUIRED)

# Создаем библиотеку из общих исходников
add_library(rpn_lib STATIC src/rpn.cpp)
target_include_directories(rpn_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Добавляем основной исполняемый файл
add_executable(rpn_calculator src/main.cpp)
target_link_libraries(rpn_calculator PRIVATE rpn_lib)

# Включаем систему тестирования
enable_testing()

# Добавляем тесты
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
    add_executable(rpn_tests tests/test_rpn.cpp)
    target_include_directories(rpn_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

    # Линкуем с библиотекой, gtest и потоками
    target_link_libraries(rpn_tests PRIVATE rpn_lib gtest_main Threads::Threads)

    add_test(NAME rpn_tests COMMAND rpn_tests)
endif()
