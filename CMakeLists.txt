project(logger)

set(LIB_SRC Appender.cc ConsoleAppender.cc FileAppender.cc Logger.cc LoggerFactory.cc
            Layout.cc Component.cc Config.cc LogEvent.cc) 

set(APP_SRC main.cc)
add_library(logger ${LIB_SRC})

add_executable(main ${APP_SRC})

target_link_libraries(main logger)
message(${PROJECT_SOURCE_DIR})

