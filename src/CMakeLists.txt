set(LIB_SRC Appender.cc ConsoleAppender.cc FileAppender.cc Logger.cc LoggerFactory.cc
            Layout.cc Component.cc Config.cc LogEvent.cc StringUtil.cc) 

set(APP_SRC main.cc)
add_library(logger ${LIB_SRC})
add_executable(main ${APP_SRC})
target_link_libraries(main logger)

message(${PROJECT_SOURCE_DIR})



add_definitions("-DGTEST_USE_OWN_TR1_TUPLE=1")
include_directories(${PROJECT_SOURCE_DIR}/gtest/include)
add_executable(test_stringutil ${PROJECT_SOURCE_DIR}/gtest/src/gtest_main.cc StringUtil_Test.cc)
target_link_libraries(test_stringutil logger gtest)

add_test(stringutil test_stringutil)
