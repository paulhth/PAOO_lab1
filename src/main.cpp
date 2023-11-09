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

    // create 2 cars
    Car c1("manufacturer1", "model1", 2020);
    Car c2("manufacturer2", "model2", 2020);

    // c1 = c2;
    // create 2 engines
    Engine e1 = Engine(510, 6);
    Engine e2 = Engine(540, 6);

    c1.AddEngine(&e1);
    c2.AddEngine(&e2);

    cout << c1.GetManufacturer() << endl;
    return 0;
}
