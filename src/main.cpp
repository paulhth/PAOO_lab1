#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "car.h"

static int money;

Car bmw = Car("BMW", "M3", "WBS8M9C50J5J78401", "Automatic", "Black", 2018, 0, 3000, 431);
Car mercedes = Car("Mercedes", "C63 AMG", "WDDGF77X99F01234", "Automatic", "White", 2020, 10, 4000, 469);
Car audi = Car("Audi", "RS7", "WAU2GAFC6GN01478", "Automatic", "Red", 2019, 100, 4500, 605);
Car toyota = Car("Toyota", "Camry", "4T1BF1FK0HU70412", "Manual", "Blue", 2017, 1000, 2000, 301);
Car honda = Car("Honda", "Civic", "2HGFC2F51HH56789", "Manual", "Grey", 2019, 1500, 1600, 205);
Car ford = Car("Ford", "Mustang", "1FATP8UH3L5151234", "Automatic", "White", 2021, 5066, 4600, 450);
Car chevrolet = Car("Chevrolet", "Camaro", "1G1FF3D78L0123456", "Manual", "Orange", 2018, 250000, 3800, 335);
Car porsche = Car("Porsche", "911", "WP0CA2A95LS123456", "Automatic", "Silver", 2020, 5, 3500, 443);
Car mazda = Car("Mazda", "MX-5", "JM1NDAB7L04123456", "Manual", "Red", 2021, 500, 20000, 181);
Car dodge = Car("Dodge", "Challenger", "2C3CDZBT9LH123456", "Automatic", "Black", 2019, 7000, 5700, 375);
Car dacia = Car("Dacia", "Sandero", "DC3CD11T9L212346", "Manual", "Grey", 2013, 700, 57000, 375);

Car GenerateCar()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int random = rand() % 10 + 1; // random number between 1 and 10

    switch (random)
    {
    case 1:
        return bmw;
    case 2:
        return mercedes;
    case 3:
        return audi;
    case 4:
        return toyota;
    case 5:
        return honda;
    case 6:
        return ford;
    case 7:
        return chevrolet;
    case 8:
        return porsche;
    case 9:
        return mazda;
    case 0:
        return dodge;
    default:
        return dacia;
    }
}

int main()
{
    char option1, option2;
    int option3;

    Car tempcar = Car(dacia);

    std::cout << "Generate car? (free) y/n: ";
    std::cin >> option1;
    if (option1 == 'y' || option1 == 'Y')
    {
        Car car = GenerateCar();
        std::cout << "You are driving a " << car.GetManufacturer() << " " << car.GetModel() << " from " << car.GetYear() << " with " << car.GetHorsepower() << " horsepower." << std::endl;
    }
    else if (option1 == 'N' || option1 == 'n')
    {
        std::cout << "Do you want to buy a car? (10000$) y/n: ";
        std::cin >> option2;
        if (option2 == 'y' || option2 == 'Y')
        {
            money = 10000;

            std::cout << "1. BMW M3 - 70000$" << std::endl;
            std::cout << "2. Mercedes C63 AMG - 65000$" << std::endl;
            std::cout << "3. Audi RS7 - 50000$" << std::endl;
            std::cout << "4. Toyota Camry - 26000$" << std::endl;
            std::cout << "5. Honda Civic - 17000$" << std::endl;
            std::cout << "6. Ford Mustang - 30000$" << std::endl;
            std::cout << "7. Chevrolet Camaro - 30000$" << std::endl;
            std::cout << "8. Porsche 911 - 120000$" << std::endl;
            std::cout << "9. Mazda MX-5 - 12000$" << std::endl;
            std::cout << "0. Dodge Challenger - 45000$" << std::endl;
            std::cout << "Choose a car: " << std::endl;

            std::cin >> option3;
            switch (option3)
            {
            case 1:
            {
                money -= 70000;
                Car tempcar = Car(bmw);
                break;
            }
            case 2:
            {
                money -= 65000;
                Car tempcar = Car(mercedes);
                break;
            }
            case 3:
            {
                money -= 50000;
                Car tempcar = Car(audi);
                break;
            }
            case 4:
            {
                money -= 26000;
                Car tempcar = Car(toyota);
                break;
            }
            case 5:
            {
                money -= 17000;
                Car tempcar = Car(honda);
                break;
            }
            case 6:
            {
                money -= 30000;
                Car tempcar = Car(ford);
                break;
            }
            case 7:
            {
                money -= 30000;
                Car tempcar = Car(chevrolet);
                break;
            }
            case 8:
            {
                money -= 120000;
                Car tempcar = Car(porsche);
                break;
            }
            case 9:
            {
                money -= 12000;
                Car tempcar = Car(mazda);
                break;
            }
            case 0:
            {
                money -= 45000;
                Car tempcar = Car(dodge);
                break;
            }
            default:
                Car tempcar = Car(dacia);
                break;
            }
            Car car = Car(tempcar);
            std::cout << "You are driving a " << car.GetManufacturer() << " " << car.GetModel() << " from " << car.GetYear() << " with " << car.GetHorsepower() << " horsepower." << std::endl;
            std::cout << "You have " << money << "$ left." << std::endl;
        }
        else if (option2 == 'N' || option2 == 'n')
        {
            std::cout << "Ok then, happy walking!" << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid input." << std::endl;
    }

    return 0;
}
