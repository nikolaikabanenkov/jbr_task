cmake_minimum_required(VERSION 3.13)

project(jbr_task LANGUAGES CXX)

add_library(spinlock STATIC src/spinlock.cc)
target_include_directories(spinlock PUBLIC src/)

set_target_properties(spinlock PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO)

add_executable(spinlock_tests test/test.cc)
find_package(Threads REQUIRED)
target_link_libraries(spinlock_tests PRIVATE spinlock Threads::Threads)
