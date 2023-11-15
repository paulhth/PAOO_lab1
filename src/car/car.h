
#ifndef CAR_H
#define CAR_H

#include <iostream>
using namespace std;
#include "../engine/engine.h"
#include "../vehicle/vehicle.h"

class Car : public Vehicle
{
private:
    string manufacturer;
    string model;
    int year;

    Engine *engine; // pointer to an Engine object

public:
    Car(); // default constructor
    Car(string manufacturer, string model, int year);
    ~Car();
    Car(const Car &other);     // copy constructor
    Car(Car &&other) noexcept; // move constructor

    void SetManufacturer(string manufacturer);
    void SetModel(string model);
    void SetYear(int year);

    Car &operator=(const Car &car);       // copy assignment operator (overloaded)
    Car &operator=(Car &&other) noexcept; // move assignment operator (overloaded)
    void AddEngine(Engine *engine);

    string GetManufacturer();
    string GetModel();
    int GetYear();

    void Honk();
    void AddFeature(string feature);
    void PrintFeatures();
    void Drive() override;
    void ChangeTires() override;
};

#endif