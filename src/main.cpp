#include <iostream>
#include <string>
#include "car.h"
#include "militarycar.h"
#include "truck.h"
#include <vector>

// overload  the + operator to return a vector of military cars
std::vector<Auto::MilitaryCar> operator+(const Auto::MilitaryCar &m1, const Auto::MilitaryCar &m2)
{
    std::vector<Auto::MilitaryCar> convoy;
    convoy.push_back(m1);
    convoy.push_back(m2);
    return convoy;
}

int main()
{

    // create 2 cars
    Car c1("BMW", "M3", 2020);
    Car c2("Porsche", "911", 2021);
    c1 = c2; // used the = operator
    cout << "AFTER '=': " << c1.GetManufacturer() << endl;

    Auto::MilitaryCar m1 = Auto::MilitaryCar("Infantry support1", "Hummer H1", 2022, true);
    Auto::MilitaryCar m2 = Auto::MilitaryCar("Infantry support2", "Hummer H2", 2023, true);

    std::vector<Auto::MilitaryCar> convoy1 = m1 + m2; // used the + operator
    std::cout << "Convoy: " << convoy1[0].GetModel() << " " << convoy1[1].GetModel() << std::endl;
    Auto::Truck t1 = Auto::Truck("Scania", "SC30", 2019, true);

    c1.Drive();
    m1.Drive();
    t1.Drive();

    c1.ChangeTires();
    m1.ChangeTires();
    t1.ChangeTires();

    return 0;
}
