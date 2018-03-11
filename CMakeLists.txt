cmake_minimum_required(VERSION 3.10)
project(arm-projects)

enable_language(C)
enable_language(CXX)
set (CMAKE_CXX_STANDARD 11)

set(ENV{PI_TOOLS_HOME} /home/user/workspace/tools)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(wiringPi)
add_subdirectory(test-arm)
