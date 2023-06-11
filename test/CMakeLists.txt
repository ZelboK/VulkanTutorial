
set(source_files
        Main.cpp
        )

set(headers

        )

add_executable(Tests
        ${source_files}
        ${headers})


target_include_directories(Tests
        PRIVATE
        ${PROJECT_SOURCE_DIR}/external
        ${PROJECT_SOURCE_DIR}/src)

target_link_libraries(Tests
        PRIVATE
        glfw
        Vulkan::Vulkan
        Source)