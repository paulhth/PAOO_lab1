#include <iostream>
#include "car.h"
#include "../vehicle/vehicle.h"
using namespace std;

// constructor
Car::Car(string manufacturer, string model, int year, Engine engine) : Vehicle()
{
    this->manufacturer = manufacturer;
    this->model = model;
    this->year = year;
    this->engine = engine;
}

Car::~Car()
{
    cout << "Destroyed: " << this->manufacturer << " - " << this->model << endl;
}

void Car::Honk()
{
    cout << this->manufacturer << " " << this->model << " Honked at another driver" << endl;
}

void Car::ChangeTires()
{
    cout << this->manufacturer << " " << this->model << endl;
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
