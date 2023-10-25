#include <iostream>
#include "car.h"
using namespace std;

Car::Car(string name, int price)
{
    this->name = name;
    this->price = price;
}

void Car::Honk()
{
    cout << "Honk! Honk!" << endl;
}