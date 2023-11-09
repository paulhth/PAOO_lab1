#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
    int horsepower;
    int cylinders;

public:
    Engine();                              // default constructor
    Engine(int horsepower, int cylinders); // constructor
    ~Engine();                             // destructor
};

#endif