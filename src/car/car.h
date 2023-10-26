#include <iostream>
using namespace std;

class Car
{
private:
    string manufacturer;
    string model;
    string VIN;
    string gearbox;
    string color;
    int year;
    int kilometers;
    int engine_capacity;
    int horsepower;

public:
    Car(string manufacturer, string model, string VIN, string gearbox, string color, int year, int kilometers, int engine_capacity, int horsepower);
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
    void SetHorsepower(int horsepower);

    string GetManufacturer();
    string GetModel();
    string GetVIN();
    string getColor();
    int GetYear();
    int GetKilometers();
    int GetEngineCapacity();
    int GetHorsepower();

    void Honk();
};