#include <iostream>
#include "car.h"
using namespace std;

extern int money;

Car::Car(string manufacturer, string model, string VIN, string gearbox, string color, int year, int kilometers, int engine_capacity, int horsepower)
{
    this->manufacturer = manufacturer;
    this->model = model;
    this->VIN = VIN;
    this->gearbox = gearbox;
    this->color = color;
    this->year = year;
    this->kilometers = kilometers;
    this->engine_capacity = engine_capacity;
    this->horsepower = horsepower;
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
      VIN(other.VIN),
      gearbox(other.gearbox),
      color(other.color),
      year(other.year),
      kilometers(other.kilometers),
      engine_capacity(other.engine_capacity),
      horsepower(other.horsepower)
{
    this->features = other.features;
}

// Move constructor
Car::Car(Car &&other) noexcept
    : manufacturer(std::move(other.manufacturer)),
      model(std::move(other.model)),
      VIN(std::move(other.VIN)),
      gearbox(std::move(other.gearbox)),
      color(std::move(other.color)),
      year(other.year),
      kilometers(other.kilometers),
      engine_capacity(other.engine_capacity),
      horsepower(other.horsepower),
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
    money -= 1000;
}

void Car::PrintFeatures()
{
    cout << this->manufacturer << " " << this->model << " - Features: " << *this->features << endl;
}

void Car::ChangeTires()
{
    cout << this->manufacturer << " " << this->model << " - Tires changed - 400$" << endl;
    money -= 400;
}

void Car::ChangeOil()
{
    cout << this->manufacturer << " " << this->model << " - Oil changed - 300$" << endl;
    money -= 300;
}

void Car::ChangeBrakes()
{
    cout << this->manufacturer << " " << this->model << " - Brakes changed - 400$" << endl;
    money -= 400;
}

void Car::Drive()
{
    this->kilometers += 100;
    cout << this->manufacturer << " " << this->model << " - Driven 100km - 20$" << endl;
    money -= 20;
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

string Car::GetVIN()
{
    return this->VIN;
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

int Car::GetHorsepower()
{
    return this->horsepower;
}

void Car::SetManufacturer(string manufacturer)
{
    this->manufacturer = manufacturer;
}

void Car::SetModel(string model)
{
    this->model = model;
}

void Car::SetVIN(string VIN)
{
    this->VIN = VIN;
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

void Car::SetHorsepower(int horsepower)
{
    this->horsepower = horsepower;
}

Car GenerateCar()
{

    int random = rand() % 10 + 1; // random number between 1 and 10

    switch (random)
    {
    case 1:
        return Car("BMW", "M3", "WBS8M9C50J5J78401", "Automatic", "Black", 2018, 0, 3000, 431);
    case 2:
        return Car("Mercedes", "C63 AMG", "WDDGF77X99F01234", "Automatic", "White", 2020, 10, 4000, 469);
    case 3:
        return Car("Audi", "RS7", "WAU2GAFC6GN01478", "Automatic", "Red", 2019, 100, 4500, 605);
    case 4:
        return Car("Toyota", "Camry", "4T1BF1FK0HU70412", "Manual", "Blue", 2017, 1000, 2000, 301);
    case 5:
        return Car("Honda", "Civic", "2HGFC2F51HH56789", "Manual", "Grey", 2019, 1500, 1600, 205);
    case 6:
        return Car("Ford", "Mustang", "1FATP8UH3L5151234", "Automatic", "White", 2021, 5066, 4600, 450);
    case 7:
        return Car("Chevrolet", "Camaro", "1G1FF3D78L0123456", "Manual", "Orange", 2018, 250000, 3800, 335);
    case 8:
        return Car("Porsche", "911", "WP0CA2A95LS123456", "Automatic", "Silver", 2020, 5, 3500, 443);
    case 9:
        return Car("Mazda", "MX-5", "JM1NDAB7L04123456", "Manual", "Red", 2021, 500, 20000, 181);
    case 0:
        return Car("Dodge", "Challenger", "2C3CDZBT9LH123456", "Automatic", "Black", 2019, 7000, 5700, 375);
    default:
        return Car("Dacia", "Sandero", "DC3CD11T9L212346", "Manual", "Grey", 2013, 700, 57000, 375);
    }
}