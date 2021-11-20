cmake_minimum_required(VERSION 3.20)
project(15618_Lock_Free_Queue)

set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(.)
include_directories(MyQueues)

add_compile_options(-Wno-deprecated-copy)
add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include)
include_directories(${gmock_SOURCE_DIR}/include)

add_executable(15618_Lock_Free_Queue
        MyQueues/lock_free_queue.hpp main.cpp test/testCASQueue.cpp)
set_target_properties(15618_Lock_Free_Queue PROPERTIES LINKER_LANGUAGE CXX)
