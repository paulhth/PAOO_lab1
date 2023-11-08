#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "car.h"
#include "militarycar.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Car car1 = Car("BMW", "M3", "Black", 2018, 0, 3000);
    MilitaryCar militaryCar1 = MilitaryCar("Tank Co.", "Armored Vehicle", "Green", 2022, 500, 1000, true);
    std::cout << militaryCar1.GetModel() << std::endl;
    return 0;
}
