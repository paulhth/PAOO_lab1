#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include "../vehicle/vehicle.h"

namespace Auto
{
    class Truck : public Vehicle
    {
    public:
        Truck(string manufacturer, string model, int year, bool hasTrailer);
        bool HasTrailer() const;
        void Drive() override;
        void ChangeTires() override;

        void getManufacturer();
        void getModel();
        void getYear();

    private:
        bool hasTrailer;
        string manufacturer;
        string model;
        int year;
    };
} // namespace Auto

#endif
