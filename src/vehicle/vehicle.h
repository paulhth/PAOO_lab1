// virtual class vehicle with 2 pure virtual functions implemented by car and militarycar
//   Path: src/vehicle/vehicle.h

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "../engine/engine.h"
using namespace std;

class Vehicle // equivalent to an interface in java
{

public:
    virtual void Drive() = 0;
    virtual void ChangeTires() = 0;
};

#endif
