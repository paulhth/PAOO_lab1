cmake_minimum_required(VERSION 3.10)

project(Tema1)

# Include the car and militarycar directories
add_subdirectory(car)
add_subdirectory(militarycar)

# Create the main executable
add_executable(Tema1 main.cpp)

# Link the main executable with CarLibrary and MilitaryCarLibrary
target_link_libraries(Tema1 CarLibrary)
target_link_libraries(Tema1 MilitaryCarLibrary)

# Specify the include directories for the main executable
target_include_directories(Tema1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/car)
target_include_directories(Tema1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/militarycar)
target_include_directories(Tema1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) # Include the current directory (for the main.cpp file)
