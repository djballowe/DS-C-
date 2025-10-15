# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(ds-cpp)

add_executable(ds-cpp
    src/main.cpp
)

target_include_directories(ds-cpp PRIVATE
    "./src"   
    "./include" 
)
