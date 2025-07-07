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

# add linkable headers from sfml
target_link_libraries(main sfml-graphics sfml-window sfml-system)

# add debug mode
option(DEGUB_MODE "Enables debug logging" OFF)
if(DEBUG_MODE)
		add_compile_definitions(DEBUG_LOGGING_ENABLED=1)
else()	
		add_compile_definitions(DEBUG_LOGGING_ENABLED=0)
endif()
