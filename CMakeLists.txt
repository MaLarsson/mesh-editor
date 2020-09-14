cmake_minimum_required(VERSION 3.15)

# set the name of the project
project(mesh_editor CXX)

# add dependencies
include(FetchContent)

FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG origin/latest
)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG origin/docking
)

FetchContent_MakeAvailable(glfw imgui)

# setup compilation targets
add_executable(mesh_editor main.cpp)
target_link_libraries(mesh_editor PRIVATE glfw)
