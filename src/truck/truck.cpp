#include "truck.h"
#include "../vehicle/vehicle.h"

namespace Auto
{
    Truck::Truck(string manufacturer, string model, int year, bool hasTrailer)
    {
        this->hasTrailer = hasTrailer;
        this->manufacturer = manufacturer;
        this->model = model;
        this->year = year;
    }

    bool Truck::HasTrailer() const
    {
        return this->hasTrailer;
    }

    void Truck::Drive()
    {
        cout << "Driving " << this->model << endl;
    }

    void Truck::ChangeTires()
    {
        cout << "Changing 18 tires for " << this->manufacturer << " " << this->model << endl;
    }
} // namespace Auto