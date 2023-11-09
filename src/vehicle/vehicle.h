// create virtual class vehicle with 2 pure virtual functions implemented by car and militarycar
//  Path: src/vehicle/vehicle.h

#ifndef VEHICLE_H
#define VEHICLE_H
#pragma once
#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void Drive() = 0;
    virtual void ChangeTires() = 0;
};

#endif
