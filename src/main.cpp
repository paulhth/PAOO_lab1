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
    std::vector<MilitaryCar> convoy1;
    // create 2 engines
    Engine e1(100, 100);
    Engine e2(100, 100);

    // create 2 military cars
    MilitaryCar m1("manufacturer1", "model1", 2020, e1, true);
    MilitaryCar m2("manufacturer2", "model2", 2020, e2, true);

    // add the 2 military cars to the convoy
    convoy1 = m1 + m2;
    std::cout << convoy1[0].GetManufacturer() << std::endl;
    return 0;
}
