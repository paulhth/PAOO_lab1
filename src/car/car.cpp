#include <iostream>
#include "car.h"
using namespace std;

Car::Car(string manufacturer, string model, string color, int year, int kilometers, int engine_capacity)
{
    this->manufacturer = manufacturer;
    this->model = model;
    this->color = color;
    this->year = year;
    this->kilometers = kilometers;
    this->engine_capacity = engine_capacity;
}

Car::~Car()
{
    if (this->features != nullptr && this->manufacturer != "" && this->model != "")
    {
        cout << "Destroyed: " << this->manufacturer << " - " << this->model << endl;
        delete features;
    }
}

// Copy constructor
Car::Car(const Car &other)
    : manufacturer(other.manufacturer),
      model(other.model),
      color(other.color),
      year(other.year),
      kilometers(other.kilometers),
      engine_capacity(other.engine_capacity)
{
    this->features = other.features;
}

// Move constructor
Car::Car(Car &&other) noexcept
    : manufacturer(std::move(other.manufacturer)),
      model(std::move(other.model)),
      color(std::move(other.color)),
      year(other.year),
      kilometers(other.kilometers),
      engine_capacity(other.engine_capacity),
      features(other.features) // Transfer the ownership of the pointer
{
    // Use memcpy
    this->features = other.features;
    other.features = nullptr;
}

void Car::Honk()
{
    cout << this->manufacturer << " " << this->model << " Honked at another driver at " << this->GetKilometers() << "km" << endl;
}

void Car::AddFeature(string feature)
{
    this->features = new string(feature); // allocate memory for a new string and copy the feature into it
    std::cout << "Added feature: " << feature << std::endl;
}

void Car::PrintFeatures()
{
    cout << this->manufacturer << " " << this->model << " - Features: " << *this->features << endl;
}

void Car::ChangeTires()
{
    cout << this->manufacturer << " " << this->model << " - Tires changed - 400$" << endl;
}

void Car::ChangeOil()
{
    cout << this->manufacturer << " " << this->model << " - Oil changed - 300$" << endl;
}

void Car::ChangeBrakes()
{
    cout << this->manufacturer << " " << this->model << " - Brakes changed - 400$" << endl;
}

void Car::Drive()
{
    this->kilometers += 100;
    cout << this->manufacturer << " " << this->model << " - Driven 100km - 20$" << endl;
}

int Crash()
{
    return 0;
}

string Car::GetManufacturer()
{
    return this->manufacturer;
}

string Car::GetModel()
{
    return this->model;
}

string Car::getColor()
{
    return this->color;
}

int Car::GetYear()
{
    return this->year;
}

int Car::GetKilometers()
{
    return this->kilometers;
}

int Car::GetEngineCapacity()
{
    return this->engine_capacity;
}

void Car::SetManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}

void Car::SetModel(string model)
{
    this->model = model;
}

void Car::SetColor(string color)
{
    this->color = color;
}

void Car::SetYear(int year)
{
    this->year = year;
}

void Car::SetKilometers(int kilometers)
{
    this->kilometers = kilometers;
}

void Car::SetEngineCapacity(int engine_capacity)
{
    this->engine_capacity = engine_capacity;
}
