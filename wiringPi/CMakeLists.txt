project(wiringPi)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src PROJECT_SOURCES)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(wiringPi STATIC ${PROJECT_SOURCES})
