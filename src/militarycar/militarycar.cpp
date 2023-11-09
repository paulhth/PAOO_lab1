#include <iostream>
#include <vector>
#include "militarycar.h"
#include "../vehicle/vehicle.h"
using namespace std;

MilitaryCar::MilitaryCar(string manufacturer, string model, int year, bool armored)
    : Car(manufacturer, model, year)
{
    this->armored = armored;
}

bool MilitaryCar::IsArmored() const
{
    return this->armored;
}
