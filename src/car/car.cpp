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
    // Currently, nothing is dynamically allocated.
    // In the future, if you have any 'new' allocations, use 'delete' here to release memory.
}

Car::Car(const Car &other) : manufacturer(other.manufacturer),
                             model(other.model),
                             VIN(other.VIN),
                             gearbox(other.gearbox),
                             color(other.color),
                             year(other.year),
                             kilometers(other.kilometers),
                             engine_capacity(other.engine_capacity),
                             horsepower(other.horsepower)
{
    // This is the copy constructor, it initializes the current object using another object's values.
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
    // This is the move constructor, it "steals" the resources from another object.
    // After this operation, the other object should not use those resources anymore.
}

void Car::Honk()
{
    cout << this->manufacturer << " " << this->model << " Honked accidentally" << endl;
}
