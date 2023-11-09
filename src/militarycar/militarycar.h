#ifndef MILITARYCAR_H
#define MILITARYCAR_H
#pragma once
#include <iostream>
using namespace std;

#include "../car/car.h"

class MilitaryCar : public Car
{
public:
    MilitaryCar(string manufacturer, string model, int year, bool armored);
    bool IsArmored() const;
    MilitaryCar CreateConvoy(MilitaryCar m1, MilitaryCar m2);

private:
    bool armored;
};

#endif
