cmake_minimum_required(VERSION 3.8)
project(game2)

# Enable the generation of compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add your source files
file(GLOB_RECURSE sources "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Add your include directories
include_directories("${CMAKE_SOURCE_DIR}/headers")

# Add your executable
add_executable(main ${sources})

