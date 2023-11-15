#ifndef MILITARYCAR_H
#define MILITARYCAR_H
#pragma once // compiler directive: compile this file only once
#include <iostream>
using namespace std;

#include "../car/car.h"

namespace Auto
{
    class MilitaryCar : public Car
    {
    public:
        MilitaryCar(string manufacturer, string model, int year, bool armored);
        bool IsArmored() const;
        MilitaryCar CreateConvoy(MilitaryCar m1, MilitaryCar m2);
        void Drive() override;
        void ChangeTires() override;

    private:
        bool armored;
    };
}
#endif
