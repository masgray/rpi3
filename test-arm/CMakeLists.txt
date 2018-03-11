project(test-arm)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src PROJECT_SOURCES)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

#set(SOURCE ${SOURCE} ${PROJECT_SOURCES} PARENT_SCOPE)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} Threads::Threads wiringPi)

ADD_CUSTOM_COMMAND(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}
    COMMAND cp -f ${CMAKE_SOURCE_DIR}/service/${PROJECT_NAME}.service ${CMAKE_BINARY_DIR}/bin/${PROJECT_NAME}.service
    COMMAND ${CMAKE_SOURCE_DIR}/copy-to-rpi.sh
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
