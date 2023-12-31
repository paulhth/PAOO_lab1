cmake_minimum_required(VERSION 3.10) # Set the minimum version of CMake to 3.10

project(Tema3) # Set the project name to Tema2


set(CMAKE_CXX_STANDARD 20) # Set the c++ version to 20 for semaphore support

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O0") # Set the release flags to -O0 (no optimization)

# Include the car and militarycar directories
add_subdirectory(car) # Include the car directory
add_subdirectory(militarycar) # Include the militarycar directory
add_subdirectory(vehicle) # Include the vehicle directory
add_subdirectory(engine) # Include the engine directory
add_subdirectory(truck) # Include the truck directory

add_executable(Tema3 main.cpp) # Create the main executable (Tema2) from the main.cpp file
#add_executable(<name of the executable> <source file(s)>)

# Link the main executable with CarLibrary, MilitaryCarLibrary and VehicleLibrary
target_link_libraries(Tema3 CarLibrary) # Link the main executable with CarLibrary
target_link_libraries(Tema3 MilitaryCarLibrary) # Link the main executable with MilitaryCarLibrary
target_link_libraries(Tema3 VehicleLibrary) # Link the main executable with VehicleLibrary
target_link_libraries(Tema3 EngineLibrary) # Link the main executable with EngineLibrary
target_link_libraries(Tema3 TruckLibrary) # Link the main executable with TruckLibrary

# Specify the include directories for the main executable
target_include_directories(Tema3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/car) # Include the car directory (for the Car.h file)
target_include_directories(Tema3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/militarycar) # Include the militarycar directory (for the MilitaryCar.h file)
target_include_directories(Tema3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vehicle) # Include the vehicle directory (for the Vehicle.h file)
target_include_directories(Tema3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/engine) # Include the vehicle directory (for the Vehicle.h file)
target_include_directories(Tema3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/truck) # Include the truck directory (for the Truck.h file)
target_include_directories(Tema3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}) # Include the current directory (for the main.cpp file)
