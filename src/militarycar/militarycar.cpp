#include <iostream>
#include "militarycar.h"
using namespace std;

MilitaryCar::MilitaryCar(string manufacturer, string model, string color, int year, int kilometers, int engine_capacity, bool armored)
    : Car(manufacturer, model, color, year, kilometers, engine_capacity), armored(armored) {}

bool MilitaryCar::IsArmored() const
{
    return armored;
}
