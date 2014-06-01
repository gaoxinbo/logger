set(SRC_LIST src/gtest-all.cc)

add_definitions("-DGTEST_USE_OWN_TR1_TUPLE=1")
include_directories(include src)
include_directories(.)
add_library(gtest ${SRC_LIST})
