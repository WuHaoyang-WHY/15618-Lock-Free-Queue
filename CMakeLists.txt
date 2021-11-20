cmake_minimum_required(VERSION 3.20)
project(15618_Lock_Free_Queue)

set(CMAKE_C_STANDARD 11)
include_directories(.)
include_directories(MyQueues)

add_executable(15618_Lock_Free_Queue
        MyQueues/lock_free_queue.hpp main.cpp)
set_target_properties(15618_Lock_Free_Queue PROPERTIES LINKER_LANGUAGE CXX)
