#ifndef MILITARYCAR_H
#define MILITARYCAR_H
#pragma once
#include <iostream>
using namespace std;

#include "../car/car.h"

class MilitaryCar : public Car
{
public:
    MilitaryCar(string manufacturer, string model, string color, int year, int kilometers, int engine_capacity, bool armored);
    bool IsArmored() const;

private:
    bool armored;
};

#endif
