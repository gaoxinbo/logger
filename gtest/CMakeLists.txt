set(SRC_LIST src/gtest-all.cc)

if(APPLE)
  add_definitions("-DGTEST_USE_OWN_TR1_TUPLE=1")
endif(APPLE)
include_directories(include src)
include_directories(.)
add_library(gtest ${SRC_LIST})
target_link_libraries(gtest pthread)
