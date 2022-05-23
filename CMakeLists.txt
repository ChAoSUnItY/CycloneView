cmake_minimum_required(VERSION 3.22)
project(CycloneView)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp
        imgui/imgui.cpp
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_impl_glfw.cpp
        imgui/imgui_impl_opengl3.cpp
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp src/ClassReader.cpp src/ClassReader.h src/ClassInfo.cpp src/ClassInfo.h src/Assertion.cpp src/Assertion.h)

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} imgui)

add_subdirectory(fmt)
add_subdirectory(glfw)

target_include_directories(${PROJECT_NAME}
        PUBLIC glfw/include
        PUBLIC imgui
        )
target_link_directories(${PROJECT_NAME}
        PRIVATE glfw/src
        PRIVATE imgui
        )
target_link_libraries(${PROJECT_NAME}
        ${OPENGL_LIBRARIES}
        fmt::fmt
        glfw
        )
