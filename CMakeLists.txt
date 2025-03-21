cmake_minimum_required(VERSION 3.17)
project(joi_grad_shopping_cart_c C)

set(CMAKE_C_STANDARD 99)

aux_source_directory(src EXE_SOURCES)
list(FILTER EXE_SOURCES INCLUDE REGEX "^.*.c$")
add_executable(${PROJECT_NAME} ${EXE_SOURCES})

aux_source_directory(test TEST_SOURCES)
list(FILTER TEST_SOURCES INCLUDE REGEX "^.*_test.c$")

if (NOT "${TEST_SOURCES}" STREQUAL "")
    list(FILTER EXE_SOURCES EXCLUDE REGEX "main.c")
    add_executable(${PROJECT_NAME}_test ${EXE_SOURCES} ${TEST_SOURCES} test/test_main.c)
    find_package(CUnit REQUIRED)
    target_link_libraries(${PROJECT_NAME}_test cunit::cunit)
endif ()
