cmake_minimum_required(VERSION 3.16)
project(MedRelay LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(medrelay
    src/main.cpp
    src/Location.cpp
    src/HospitalRecommender.cpp
)
target_include_directories(medrelay PRIVATE include)
