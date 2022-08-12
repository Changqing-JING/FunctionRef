cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

project(FunctionRef)

aux_source_directory(src sourceFiles)

add_executable(${PROJECT_NAME} ${sourceFiles})