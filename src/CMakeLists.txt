cmake_minimum_required(VERSION 3.10)

project(Tema1)

# Include the car directory
add_subdirectory(car)

# Create the main executable
add_executable(Tema1 main.cpp)
target_link_libraries(Tema1 CarLibrary)

# Specify the include directories for the main executable
target_include_directories(Tema1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/car)
