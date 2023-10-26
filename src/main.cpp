#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "car.h"

Car GenerateCar()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int random = rand() % 10 + 1; // random number between 1 and 10

    switch (random)
    {
    case 1:
        return Car("BMW", "M3", "WBS8M9C50J5J78401", "Automatic", "Black", 2018, 0, 3000, 431);
    case 2:
        return Car("Mercedes", "C63 AMG", "WDDGF77X99F01234", "Automatic", "White", 2020, 10, 4000, 469);
    case 3:
        return Car("Audi", "RS7", "WAU2GAFC6GN01478", "Automatic", "Red", 2019, 100, 4500, 605);
    case 4:
        return Car("Toyota", "Camry", "4T1BF1FK0HU70412", "Manual", "Blue", 2017, 1000, 2000, 301);
    case 5:
        return Car("Honda", "Civic", "2HGFC2F51HH56789", "Manual", "Grey", 2019, 1500, 1600, 205);
    case 6:
        return Car("Ford", "Mustang", "1FATP8UH3L5151234", "Automatic", "White", 2021, 5066, 4600, 450);
    case 7:
        return Car("Chevrolet", "Camaro", "1G1FF3D78L0123456", "Manual", "Orange", 2018, 250000, 3800, 335);
    case 8:
        return Car("Porsche", "911", "WP0CA2A95LS123456", "Automatic", "Silver", 2020, 5, 3500, 443);
    case 9:
        return Car("Mazda", "MX-5", "JM1NDAB7L04123456", "Manual", "Red", 2021, 500, 20000, 181);
    case 0:
        return Car("Dodge", "Challenger", "2C3CDZBT9LH123456", "Automatic", "Black", 2019, 7000, 5700, 375);
    default:
        return Car("Dacia", "Sandero", "DC3CD11T9L212346", "Manual", "Grey", 2013, 700, 57000, 375);
    }
}

int main()
{
    Car car1 = Car("BMW", "M3", "WBS8M9C50J5J78404", "Automatic", "Black", 2018, 0, 3000, 431);
    Car car2 = GenerateCar();
    car2.Honk();
    car1.Honk();
    return 0;
}
