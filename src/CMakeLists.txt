
set(source_files
        TriangleApplication.cpp
        FileUtil.cpp)

set(headers
        TriangleApplication.h
        QueueFamilyIndices.h
        SwapChainSupportDetails.h
        FileUtil.h BicubicSplineInterpolator.h)

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