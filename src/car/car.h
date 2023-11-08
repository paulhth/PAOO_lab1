#pragma once
#include <iostream>
using namespace std;

class Car
{
private:
    string manufacturer;
    string model;
    string color;
    int year;
    int kilometers;
    int engine_capacity;

    string *features;

public:
    Car(string manufacturer, string model, string color, int year, int kilometers, int engine_capacity);
    ~Car();
    Car(const Car &other);
    Car(Car &&other) noexcept;

    void SetManufacturer(string manufacturer);
    void SetModel(string model);
    void SetVIN(string VIN);
    void SetColor(string color);
    void SetYear(int year);
    void SetKilometers(int kilometers);
    void SetEngineCapacity(int engine_capacity);

    string GetManufacturer();
    string GetModel();
    string getColor();
    int GetYear();
    int GetKilometers();
    int GetEngineCapacity();

    void Honk();
    void AddFeature(string feature);
    void PrintFeatures();
    void Drive();
    void ChangeTires();
    void ChangeOil();
    void ChangeBrakes();
    int Crash();
};