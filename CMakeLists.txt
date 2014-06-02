cmake_minimum_required(VERSION 2.8)
project(logger)

ENABLE_TESTING()
add_definitions(-Wall -Werror -Wno-unused-variable -Wno-unused-private-field)
add_subdirectory(gtest)
add_subdirectory(src)
