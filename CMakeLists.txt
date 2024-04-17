cmake_minimum_required(VERSION 3.20..3.25)

project(
  MaterialVisualizer
  VERSION 0.1
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json 3.11.3 REQUIRED)

configure_file(configureFile.h.in configureFile.h)

add_executable("${PROJECT_NAME}" main.cpp)

target_link_libraries("${PROJECT_NAME}" PRIVATE nlohmann_json::nlohmann_json)

target_include_directories("${PROJECT_NAME}" PUBLIC "${PROJECT_BINARY_DIR}")
