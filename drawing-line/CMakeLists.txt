cmake_minimum_required(VERSION 3.16)
project(drawing_line)

set(CMAKE_CXX_STANDARD 23)

# Specify the directories where the libraries are located
set(GLEW_LIB_PATH "C:/opengl/glew/lib/Release/x64/")
set(GLFW_LIB_PATH "C:/opengl/glfw/lib-vc2022/")

set(GLEW_INCLUDE_PATH "C:/opengl/glew/include")
set(GLFW_INCLUDE_PATH "C:/opengl/glfw/include")

# Add the paths to look for header files
include_directories(${GLEW_INCLUDE_PATH} ${GLFW_INCLUDE_PATH})

# Add the libraries
find_library(GLEW_LIB glew32 ${GLEW_LIB_PATH})
find_library(GLFW_LIB glfw3 ${GLFW_LIB_PATH})

add_executable(drawing_line main.cpp)

# Link the libraries
target_link_libraries(drawing_line ${GLEW_LIB} ${GLFW_LIB} opengl32)