// virtual class vehicle with 2 pure virtual functions implemented by car and militarycar
//   Path: src/vehicle/vehicle.h

#ifndef VEHICLE_H
#define VEHICLE_H
#pragma once
#include <iostream>
#include "../engine/engine.h"
using namespace std;

class Vehicle
{
private:
    Engine engine;

public:
    Vehicle();
    virtual void Drive() = 0;
    virtual void ChangeTires() = 0;
};

#endif
