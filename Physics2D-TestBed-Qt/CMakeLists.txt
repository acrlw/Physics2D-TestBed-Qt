# CMakeList.txt: Physics2D-TestBed-Qt 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

# 将源代码添加到此项目的可执行文件。
add_executable (Physics2D-TestBed-Qt "main.cpp")
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_library(Physics2DLib "${PROJECT_SOURCE_DIR}/dependencies/Physics2D/lib")
target_link_libraries(Physics2D-TestBed-Qt PRIVATE Qt5::Widgets)
target_include_directories(Physics2D-TestBed-Qt PRIVATE "${PROJECT_SOURCE_DIR}/dependencies/Physics2D/include")
include_directories("${PROJECT_SOURCE_DIR}/dependencies/Physics2D/include")
link_libraries("${PROJECT_SOURCE_DIR}/dependencies/Physics2D/lib")
# TODO: 如有需要，请添加测试并安装目标。
