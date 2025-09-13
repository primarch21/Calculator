include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_MakeAvailable(googletest)

# Добавляем исполняемый файл для тестов
add_executable(rpn_tests test_rpn.cpp)

# Линкуем с Google Test
target_link_libraries(rpn_tests PRIVATE gtest_main)

# Добавляем include директории
target_include_directories(rpn_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Добавляем тест в CTest
add_test(NAME rpn_tests COMMAND rpn_tests)
