#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "car.h"

static int money;
/*
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
*/
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
    money = 100000;
    srand(static_cast<unsigned int>(time(nullptr)));
    Car car = GenerateCar();
    string name = car.GetManufacturer();
    if (name == "BMW")
        money -= 50000;
    else if (name == "Mercedes")
        money -= 60000;
    else if (name == "Audi")
        money -= 70000;
    else if (name == "Toyota")
        money -= 20000;
    else if (name == "Honda")
        money -= 25000;
    else if (name == "Ford")
        money -= 30000;
    else if (name == "Chevrolet")
        money -= 35000;
    else if (name == "Porsche")
        money -= 40000;
    else if (name == "Mazda")
        money -= 45000;
    else if (name == "Dodge")
        money -= 50000;
    else if (name == "Dacia")
        money -= 10000;
    else
        money -= 10000;

    cout << "You have 100000$ and your car is a " << name << " " << car.GetModel() << endl
         << "Drive?" << endl;
    char answer;
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
        for (int i = 0; i < 100; i++)
        {
            car.Drive();

            // random number between 1 and 20
            int random = rand() % 20 + 1;

            switch (random)
            {
            case 1:
                car.ChangeTires();
                money -= 4000;
                break;
            case 2:
                car.ChangeOil();
                money -= 1000;
                break;
            case 3:
                car.ChangeBrakes();
                money -= 800;
                break;

            case 4:
                car.AddFeature("Infotainment update");
                money -= 1000;
                break;

            case 5:
                car.AddFeature("Repaint");
                money -= 1000;
                break;
            default:
                money -= 100; // gas
                break;
            }
        }
    cout << "You have " << money << "$ left" << endl;
    cout << "Kilometers done: " << car.GetKilometers() << endl;
    return 0;
}
