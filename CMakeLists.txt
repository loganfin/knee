cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)

project(locket LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC
    ${CMAKE_CURRENT_LIST_DIR}/src/locket/socket.cpp
    )

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )
