#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "car.h"
#include "militarycar.h"
#include <vector>

// overload  the + operator to return a vector of military cars
std::vector<MilitaryCar> operator+(const MilitaryCar &m1, const MilitaryCar &m2)
{
    std::vector<MilitaryCar> convoy;
    convoy.push_back(m1);
    convoy.push_back(m2);
    return convoy;
}

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    // Car car1 = Car("BMW", "M3", "Black", 2018, 0, 3000);
    MilitaryCar militaryCar1 = MilitaryCar("Tank Co.", "Armored Vehicle", "Green", 2022, 500, 1000, true);
    MilitaryCar militaryCar2 = MilitaryCar("M1 Abrams", "Tank", "Desert Camo", 2022, 500, 1000, true);
    std::cout << militaryCar2.GetModel() << std::endl;
    militaryCar2.Honk();
    std::vector<MilitaryCar> convoy = militaryCar1 + militaryCar2;
    std::cout << convoy[1].GetModel() << std::endl;

    return 0;
}
