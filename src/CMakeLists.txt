
set(source_files
        TriangleApplication.cpp
        )

set(headers
        TriangleApplication.h
        QueueFamilyIndices.h)

add_library(Source
        ${source_files}
        ${headers})


target_include_directories(Source
        PRIVATE
        ${PROJECT_SOURCE_DIR}/external)
target_link_libraries(Source
        PRIVATE
        glfw
        Vulkan::Vulkan)