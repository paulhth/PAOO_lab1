#include <iostream>
#include <string>
#include "car.h"

int main()
{
    Car car1 = Car("BMW", "M3", "WBS8M9C50J5J78404", "Automatic", "Black", 2018, 0, 3000, 431);
    car1.Honk();
    return 0;
}
