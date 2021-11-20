cmake_minimum_required(VERSION 3.20)
project(15618_Lock_Free_Queue)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)
include_directories(MyQueues)

# GTEST Import
find_package(GTest REQUIRED)
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${gmock_SOURCE_DIR}/include)

add_executable(unittest test/testCASQueue.cpp)
target_link_libraries(unittest gtest gtest_main)

add_executable(15618_Lock_Free_Queue
        MyQueues/lock_free_queue.hpp main.cpp)


set_target_properties(15618_Lock_Free_Queue PROPERTIES LINKER_LANGUAGE CXX)
