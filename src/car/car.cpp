#include <iostream>
#include "car.h"
#include "../vehicle/vehicle.h"

using namespace std;

/*
Rule of 5: Copy constructor, copy assignment operator, move constructor, move assignment operator, destructor
Copy constructor: line 25
Copy assignment operator: line 39
Move constructor: line 55
Move assignment operator: line 64
Destructor: line 64
*/

// Basic Constructor
Car::Car(string manufacturer, string model, int year) : Vehicle()
{
    this->manufacturer = manufacturer;
    this->model = model;
    this->year = year;
    this->engine = new Engine();
}

// Copy constructor used to create a new object as a copy of an existing object
Car::Car(const Car &other)
    : manufacturer(other.manufacturer), model(other.model), year(other.year)
{
    if (other.engine)
    {
        engine = new Engine(*other.engine); // Create new engine object and copy the data from the parameter object's engine
    }
    else
    {
        engine = nullptr;
    }
}

// Copy assignment operator used to overwrite the contents of an existing object with another object's data
Car &Car::operator=(const Car &other)
{
    if (this != &other)
    {
        manufacturer = other.manufacturer;
        model = other.model;
        year = other.year;
        Engine *new_engine = other.engine ? new Engine(*other.engine) : nullptr; // Deep copy of engine
        delete engine;                                                           // Delete old engine
        engine = new_engine;                                                     // Assign the new engine
    }
    return *this;
}

// Move constructor used to create a new object by moving data from an existing (temporary, rvalue) object
Car::Car(Car &&other) noexcept
    : manufacturer(std::move(other.manufacturer)),
      model(std::move(other.model)),
      year(other.year),
      engine(other.engine)
{
    other.engine = nullptr; // Ensure the parameter object doesn't delete the pointer to engine
}

// Move assignment operator used like the move constructor but doesn't create a copy
Car &Car::operator=(Car &&other) noexcept
{
    if (this != &other)
    {
        delete engine; // Delete current engine
        // Transfer ownership
        manufacturer = move(other.manufacturer);
        model = move(other.model);
        year = other.year;
        engine = other.engine;
        other.engine = nullptr;
    }
    return *this;
}

// Destructor
Car::~Car()
{
    // cout << "Destroyed: " << this->manufacturer << " - " << this->model << endl;
    if (engine != nullptr)
    {
        delete engine;
    }
}

void Car::AddEngine(Engine *engine)
{
    this->engine = engine;
}

void Car::Honk()
{
    cout << this->manufacturer << " " << this->model << " Honked at another driver" << endl;
}

void Car::ChangeTires()
{
    cout << "Changing 4 tires for " << this->manufacturer << " " << this->model << endl;
}

void Car::Drive()
{
    cout << "Driving " << this->manufacturer << " " << this->model << endl;
}

string Car::GetManufacturer()
{
    return this->manufacturer;
}

string Car::GetModel()
{
    return this->model;
}

int Car::GetYear()
{
    return this->year;
}

void Car::SetManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}

void Car::SetModel(string model)
{
    this->model = model;
}

void Car::SetYear(int year)
{
    this->year = year;
}
