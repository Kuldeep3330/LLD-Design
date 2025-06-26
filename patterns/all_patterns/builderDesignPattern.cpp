#include <iostream>
#include <string>
using namespace std;
/*
Building a Car
Scenario:
You are designing a system to create different types of cars (e.g., Sedan, SUV). Each car has multiple components like the engine, wheels, and interior.
*/
// // 1.product
// class Car
// {
// public:
//     string engine;
//     string wheels;
//     void showSpecification() const
//     {
//         cout << "Engine: " << engine << endl;
//         cout << "Wheels: " << wheels << endl;
//     }
// };
// // Builder Interface
// class CarBuilder
// {
// public:
//     virtual void buildEngine() = 0;
//     virtual void buildwheels() = 0;
//     virtual Car *getCar() = 0;
//     virtual ~CarBuilder() = default;
// };
// // 3. concrete builder
// class SedanBuilder : public CarBuilder
// {
// private:
//     Car *car;

// public:
//     SedanBuilder()
//     {
//         car = new Car();
//     }
//     void buildEngine() override
//     {
//         car->engine = "4L CNG engine";
//     }
//     void buildwheels() override
//     {
//         car->wheels = "16 inch alloy wheels";
//     }
//     Car *getCar() override
//     {
//         return car;
//     }
// };
// class NexonBuilder : public CarBuilder
// {
// private:
//     Car *car;

// public:
//     NexonBuilder()
//     {
//         car = new Car();
//     }
//     void buildEngine() override
//     {
//         car->engine = "8.5L CNG engine";
//     }
//     void buildwheels() override
//     {
//         car->wheels = "24 inch alloy wheels";
//     }
//     Car *getCar() override
//     {
//         return car;
//     }
// };
// // Director
// class CarDirector
// {
// private:
//     CarBuilder *builder;

// public:
//     void setBuilder(CarBuilder *builder)
//     {
//         this->builder = builder;
//     }
//     Car *constructCar()
//     {
//         builder->buildEngine();
//         builder->buildwheels();
//         return builder->getCar();
//     }
// };

// Building a computer
class Computer
{
public:
    string cpu;
    string ram;
    void showSpecifications() const
    {
        cout << "CPU: " << cpu << endl;
        cout << "RAM: " << ram << endl;
    }
};

// Builder Interface
class ComputerBuilder
{
public:
    virtual void buildCPU() = 0;
    virtual void buildRAM() = 0;
    virtual Computer *getComputer() = 0;
    virtual ~ComputerBuilder() = default;
};

// concrete builders
class GamingPCBuilder : public ComputerBuilder
{
private:
    Computer *computer;

public:
    GamingPCBuilder() { computer = new Computer(); }
    void buildCPU() override
    {
        computer->cpu = "Intel i9 2nfajdk";
    }
    void buildRAM() override
    {
        computer->ram = "32GB ddrj";
    }
    Computer *getComputer() override
    {
        return computer;
    }
};
class WorkstationBuilder : public ComputerBuilder
{
private:
    Computer *computer;

public:
    WorkstationBuilder() { computer = new Computer(); }
    void buildCPU() override
    {
        computer->cpu = "AMD Ryzen 2nfajdk";
    }
    void buildRAM() override
    {
        computer->ram = "128GB ddrj";
    }
    Computer *getComputer() override
    {
        return computer;
    }
};
// Director
class ComputerDirector
{
private:
    ComputerBuilder *builder;

public:
    void setBuilder(ComputerBuilder *builder)
    {
        this->builder = builder;
    }
    Computer *constructComputer()
    {
        builder->buildCPU();
        builder->buildRAM();
        return builder->getComputer();
    }
};
int main()
{
    // client code for building computer
    ComputerDirector director;
    //  Build a Gaming PC
    ComputerBuilder *gamingBuilder = new GamingPCBuilder();
    director.setBuilder(gamingBuilder);
    Computer *gamingPC = director.constructComputer();
    cout << "Gaming PC Specifications:\n";
    gamingPC->showSpecifications();
    delete gamingBuilder;

    // Build a Workstation
    ComputerBuilder *workstationBuilder = new WorkstationBuilder();
    director.setBuilder(workstationBuilder);
    Computer *workstation = director.constructComputer();
    cout << "\nWorkstation Specifications:\n";
    workstation->showSpecifications();
    delete workstationBuilder;

    delete gamingPC;
    delete workstation;

    // client code for building car
    //  CarDirector director;
    //  CarBuilder *sedanBuilder = new SedanBuilder();
    //  director.setBuilder(sedanBuilder);
    //  Car *sedan = director.constructCar();
    //  cout << "sedan specifictaions\n";
    //  sedan->showSpecification();

    // delete sedanBuilder;

    return 0;
}