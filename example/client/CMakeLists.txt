cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(client LANGUAGES CXX)

add_executable(${CMAKE_PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    )

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../.. ${CMAKE_BINARY_DIR}/lib/locket)

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
        locket
    )
