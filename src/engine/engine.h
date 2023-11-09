class Engine
{
private:
    int horsepower;
    int cylinders;

public:
    Engine();                              // default constructor
    Engine(int horsepower, int cylinders); // constructor
    ~Engine();                             // destructor
    // Engine(const Engine &other);
    // Engine(Engine &&other) noexcept;
};