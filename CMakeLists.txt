cmake_minimum_required(VERSION 3.25)
project(Vulk)

set(CMAKE_CXX_STANDARD 20)

add_executable(Vulk main.cpp
        src/TriangleApplication.cpp
        src/TriangleApplication.h)

find_package(Vulkan REQUIRED)
find_package(glfw3 3.3 REQUIRED)

target_include_directories(Vulk
        PRIVATE
        ${PROJECT_SOURCE_DIR}/external)
target_link_libraries(Vulk
        PRIVATE
        glfw
        Vulkan::Vulkan
        Source)

add_subdirectory(src)
add_subdirectory(test)