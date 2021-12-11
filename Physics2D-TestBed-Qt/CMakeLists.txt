
cmake_minimum_required (VERSION 3.8)

set(PHYSICS2D_ALL)
file(GLOB_RECURSE PHYSICS2D_ALL ./dependencies/Physics2D/*.*)

set(TESTBED_HEADER_ALL)
file(GLOB_RECURSE TESTBED_HEADER_ALL ./include/*.h)
set(TESTBED_SOURCE_ALL)
file(GLOB_RECURSE TESTBED_SOURCE_ALL ./source/*.cpp)


add_executable (Physics2D-TestBed-Qt "main.cpp" ${PHYSICS2D_ALL} ${TESTBED_HEADER_ALL} 
${TESTBED_SOURCE_ALL})

find_package(Qt5 COMPONENTS Widgets REQUIRED)
target_link_libraries(Physics2D-TestBed-Qt PRIVATE Qt5::Widgets)