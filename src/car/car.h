
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

    void SetManufacturer(string manufacturer);
    void SetModel(string model);
    void SetYear(int year);

    Car &operator=(const Car &car);
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