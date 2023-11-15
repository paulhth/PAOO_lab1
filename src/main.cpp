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
    cout << "BEFORE '=': " << c1.GetManufacturer() << endl;
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

    /*---------------------------------------RO5---------------------------------------------*/

    std::cout << "---------------------Ro5"
              << "---------------------" << std::endl;

    Car car1("BMW", "M3", 2020);
    std::cout << "Car 1 created: " << car1.GetManufacturer() << " " << car1.GetModel() << std::endl;

    // Copy constructor to create a new car
    Car car2 = car1;
    std::cout << "Car 2 created using copy constructor: " << car2.GetManufacturer() << " " << car2.GetModel() << std::endl;

    // car2 is a separate object from car1
    car2.SetManufacturer("Audi");
    car2.SetModel("A4");
    car2.SetYear(2021);
    std::cout << "Car 2 modified: " << car2.GetManufacturer() << " " << car2.GetModel() << std::endl;

    // Copy assignment operator
    Car car3("Mercedes", "C-Class", 2019);
    std::cout << "Car 3 before assignment: " << car3.GetManufacturer() << " " << car3.GetModel() << std::endl;
    car3 = car2;
    std::cout << "Car 3 after assignment: " << car3.GetManufacturer() << " " << car3.GetModel() << std::endl;

    // Move constructor to create a new car
    Car car4 = car3;
    std::cout << "Car 4 created using move constructor: " << car4.GetManufacturer() << " " << car4.GetModel() << std::endl;

    // Check car3 after moving its resources
    std::cout << "Car 3 after moving resources to Car 4: " << car3.GetManufacturer() << " " << car3.GetModel() << std::endl;

    // Move assignment operator
    Car car5("Lexus", "RX", 2022);
    std::cout << "Car 5 before move assignment: " << car5.GetManufacturer() << " " << car5.GetModel() << std::endl;
    car5 = car4; // car5 already exists
    std::cout << "Car 5 after move assignment: " << car5.GetManufacturer() << " " << car5.GetModel() << std::endl;

    std::cout << "Car 4 after moving resources to Car 5: " << car4.GetManufacturer() << " " << car4.GetModel() << std::endl;

    return 0;
}
