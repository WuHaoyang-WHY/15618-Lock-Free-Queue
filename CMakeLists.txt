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

# Benchmark import
find_package(benchmark REQUIRED)
#add_subdirectory(lib/benchmark)
include_directories(lib/benchmark/include)
add_executable(run_benchmark performance/performance_analysis.cpp)
target_link_libraries(run_benchmark benchmark::benchmark)
# set output file env var
set(ENV{BENCHMARK_OUT_FORMAT} csv)
set(ENV{BENCHMARK_OUT} /performance/test.csv)

add_executable(unittest test/testCASQueue.cpp test/testCourseLockQueue.cpp test/testFineLockQueue.cpp)
target_link_libraries(unittest gtest gtest_main)

add_executable(15618_Lock_Free_Queue
        MyQueues/lock_free_queue.hpp main.cpp MyQueues/coarse_lock_queue.hpp MyQueues/fine_lock_queue.hpp)


set_target_properties(15618_Lock_Free_Queue PROPERTIES LINKER_LANGUAGE CXX)
