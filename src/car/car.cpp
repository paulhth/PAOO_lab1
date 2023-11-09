#include <iostream>
#include "car.h"
#include "../vehicle/vehicle.h"

using namespace std;

// constructor
Car::Car(string manufacturer, string model, int year) : Vehicle()
{
    this->manufacturer = manufacturer;
    this->model = model;
    this->year = year;
    this->engine = new Engine();
}

// generate overloading operator for =
Car &Car::operator=(const Car &car)
{
    // verifiy if the current car is equal to passed car
    if (this == &car)
    {
        return *this;
    }
    this->manufacturer = car.manufacturer;
    this->model = car.model;
    this->year = car.year;
    this->engine = car.engine;
    return *this;
}

Car::~Car()
{
    // cout << "Destroyed: " << this->manufacturer << " - " << this->model << endl;
    if (engine != nullptr)
    {
        delete engine;
    }
}

// add addEngine method
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
