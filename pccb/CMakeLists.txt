cmake_minimum_required(VERSION 3.6)
project(pccb)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_PROBLEM_1.6.1-1 main1.6.1-1.cpp cmake-build-debug/main1.6.1-1.cpp)
add_executable(p161-1 ${SOURCE_PROBLEM_1.6.1-1})