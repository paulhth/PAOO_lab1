#include <iostream>
#include "engine.h"

Engine::Engine() // default constructor
{
    this->horsepower = 0;
    this->cylinders = 0;
}

Engine::Engine(int horsepower, int cylinders) // constructor
{
    this->horsepower = horsepower;
    this->cylinders = cylinders;
}

Engine::~Engine() // destructor
{
    std::cout << "Destroyed Engine" << std::endl;
}
