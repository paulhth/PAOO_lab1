#include <iostream>
#include <vector>
#include "militarycar.h"
#include "../vehicle/vehicle.h"
using namespace std;

namespace Auto
{
    MilitaryCar::MilitaryCar(string manufacturer, string model, int year, bool armored)
        : Car(manufacturer, model, year)
    {
        this->armored = armored;
    }

    bool MilitaryCar::IsArmored() const
    {
        return this->armored;
    }

    void MilitaryCar::Drive()
    {
        cout << "Driving " << this->GetManufacturer() << " " << this->GetModel() << endl;
    }

    void MilitaryCar::ChangeTires()
    {
        cout << "Changing 6 tires for " << this->GetManufacturer() << " " << this->GetModel() << endl;
    }
} // namespace Auto