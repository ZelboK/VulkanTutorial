cmake_minimum_required(VERSION 3.25)
project(Vulk)

set(CMAKE_CXX_STANDARD 20)

add_executable(Vulk main.cpp
        src/TriangleApplication.cpp
        src/TriangleApplication.h)

find_package(Vulkan REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
find_package(OpenCV CONFIG REQUIRED)

target_include_directories(Vulk
        PRIVATE
        ${PROJECT_SOURCE_DIR}/external)

target_link_libraries(Vulk
        PRIVATE
        glfw
        Vulkan::Vulkan
        Source
        Catch2::Catch2 Catch2::Catch2WithMain
        ${OpenCV_LIBS})


add_subdirectory(src)
add_subdirectory(test)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/shaders"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/shaders
        ${CMAKE_BINARY_DIR}/shaders
        COMMENT "Copying shaders to build directory"
        DEPENDS ${CMAKE_SOURCE_DIR}/shaders
)

add_custom_command(
        OUTPUT "${CMAKE_BINARY_DIR}/resources"
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_BINARY_DIR}/resources
        COMMENT "Copying resources to build directory"
        DEPENDS ${CMAKE_SOURCE_DIR}/resources
)

add_custom_target(
        copy_shaders_target ALL
        DEPENDS "${CMAKE_BINARY_DIR}/shaders"
)

add_custom_target(
        copy_resources_target ALL
        DEPENDS "${CMAKE_BINARY_DIR}/resources"
)

add_dependencies(Vulk
        copy_shaders_target
        copy_resources_target)