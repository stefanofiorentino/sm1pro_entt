cmake_minimum_required(VERSION 3.13)
project(sm1pro_entt)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/entt/src
        ${CMAKE_SOURCE_DIR}/setInterval/src
)

add_subdirectory(mosquitopp_client)

add_executable(
        sm1pro_entt
        src/main.cpp
)

link_directories(
        ${CMAKE_BINARY_DIR}/
)

target_link_libraries(
        sm1pro_entt
        mosquittoppWrapperLib
        pthread
)

# useful only for development purpose
file(GLOB_RECURSE header_only_HPP
        "*.hpp"
        )

add_library(never_link_this ${header_only_HPP})
add_library(objlib OBJECT ${header_only_HPP})
set_target_properties(never_link_this PROPERTIES LINKER_LANGUAGE CXX)