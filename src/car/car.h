#pragma once
#include <iostream>
using namespace std;

#include "../vehicle/vehicle.h"

class Car : public Vehicle
{
private:
    string manufacturer;
    string model;
    int year;

    Engine engine;

public:
    Car(string manufacturer, string model, int year, Engine engine);
    ~Car();

    void SetManufacturer(string manufacturer);
    void SetModel(string model);
    void SetYear(int year);

    string GetManufacturer();
    string GetModel();
    int GetYear();

    void Honk();
    void AddFeature(string feature);
    void PrintFeatures();
    void Drive() override;
    void ChangeTires() override;
};