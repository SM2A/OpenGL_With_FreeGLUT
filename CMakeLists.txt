cmake_minimum_required(VERSION 3.17)
project(opengl_tutorial)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(opengl_tutorial main.cpp)

target_link_libraries(opengl_tutorial ${OPENGL_LIBRARIES})
target_link_libraries(opengl_tutorial ${GLUT_LIBRARIES})
target_link_libraries(opengl_tutorial -lopengl32 -lfreeglut)
