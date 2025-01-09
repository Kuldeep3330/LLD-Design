#include <iostream>
#include <string>
using namespace std;
class Prototype
{
public:
    virtual Prototype *clone() const = 0;
    virtual void showDetails() const = 0;
    virtual ~Prototype() {}
};
// concrete prototypes
class Car : public Prototype
{
private:
    string model;
    int price;

public:
    Car(const string &model, int price) : model(model), price(price) {}
    // Clone method
    Prototype *clone() const override
    {
        return new Car(*this); // Copy itself
    }
    void showDetails() const override
    {
        cout << "Car Model: " << model << ", Price: $" << price << endl;
    }
};
int main()
{
    Prototype *carPrototype = new Car("Sedan", 20000);
    // Clone prototypes to create new objects
    Prototype *clonedCar1 = carPrototype->clone();
    Prototype *clonedCar2 = carPrototype->clone();
    cout << "Cloned Objects:" << endl;
    clonedCar1->showDetails();
    clonedCar2->showDetails();
    delete carPrototype;
    delete clonedCar1;
    delete clonedCar2;
    return 0;
}