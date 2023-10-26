#include <iostream>
#include "car.h"
using namespace std;

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
    cout << "Destructor: " << this->manufacturer << " - " << this->model << endl;
    delete[] this->features;
}

Car::Car(const Car &other) : manufacturer(other.manufacturer), // copy constructor
                             model(other.model),
                             VIN(other.VIN),
                             gearbox(other.gearbox),
                             color(other.color),
                             year(other.year),
                             kilometers(other.kilometers),
                             engine_capacity(other.engine_capacity),
                             horsepower(other.horsepower)
{
    this->manufacturer = other.manufacturer;
    this->model = other.model;
    this->VIN = other.VIN;
    this->gearbox = other.gearbox;
    this->color = other.color;
    this->year = other.year;
    this->kilometers = other.kilometers;
    this->engine_capacity = other.engine_capacity;
    this->horsepower = other.horsepower;
    this->features = new string(*other.features); // allocate memory for a new string and copy the feature into it
}

Car::Car(Car &&other) noexcept : manufacturer(std::move(other.manufacturer)),
                                 model(std::move(other.model)),
                                 VIN(std::move(other.VIN)),
                                 gearbox(std::move(other.gearbox)),
                                 color(std::move(other.color)),
                                 year(other.year),
                                 kilometers(other.kilometers),
                                 engine_capacity(other.engine_capacity),
                                 horsepower(other.horsepower)
{
    this->manufacturer = move(other.manufacturer);
    this->model = move(other.model);
    this->VIN = move(other.VIN);
    this->gearbox = move(other.gearbox);
    this->color = move(other.color);
    this->year = other.year;
    this->kilometers = other.kilometers;
    this->engine_capacity = other.engine_capacity;
    this->horsepower = other.horsepower;
    this->features = new string(*other.features); // allocate memory for a new string and move the feature into it
}

void Car::Honk()
{
    cout << this->manufacturer << " " << this->model << " Honked accidentally" << endl;
}

void Car::AddFeature(string feature)
{
    this->features = new string(feature); // allocate memory for a new string and copy the feature into it
}
