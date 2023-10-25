cmake_minimum_required(VERSION 3.10)

project(ExampleProject)

# Include the car directory
add_subdirectory(car)

# Create the main executable
add_executable(ExampleProject main.cpp)
target_link_libraries(ExampleProject CarLibrary)

# Specify the include directories for the main executable
target_include_directories(ExampleProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/car)
