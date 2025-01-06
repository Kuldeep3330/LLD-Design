#include <iostream>
#include <string>

using namespace std;

class Coffee
{
public:
    virtual string getDescription() const = 0;
    virtual int getCost() const = 0;
    virtual ~Coffee() = default;
};
// simplecoffee is a coffee
class SimpleCoffee : public Coffee
{
public:
    string getDescription() const override
    {
        return "simple coffee";
    }
    int getCost() const override
    {
        return 10;
    }
};

// decorator
//  means coffeeDecorator is a coffee and coffeedecorator has a coffee
class CoffeeDecorator : public Coffee
{
protected:
    Coffee *coffee;

public:
    CoffeeDecorator(Coffee *coffee) : coffee(coffee) {}
    string getDescription() const override
    {
        return coffee->getDescription();
    }
    int getCost() const override
    {
        return coffee->getCost();
    }
    virtual ~CoffeeDecorator()
    {
        delete coffee;
    }
};
// concrete decorator
class Milk : public CoffeeDecorator
{
public:
    Milk(Coffee *coffee) : CoffeeDecorator(coffee) {}
    string getDescription() const override
    {
        return coffee->getDescription() + " Milk";
    }
    int getCost() const override
    {
        return coffee->getCost() + 10;
    }
};
class Caramel : public CoffeeDecorator
{
public:
    Caramel(Coffee *coffee) : CoffeeDecorator(coffee) {}
    string getDescription() const override
    {
        return coffee->getDescription() + " caramel";
    }
    int getCost() const override
    {
        return coffee->getCost() + 20;
    }
};
int main()
{
    Coffee *coffee = new SimpleCoffee();
    cout << coffee->getDescription() << " " << coffee->getCost() << endl;
    coffee = new Milk(coffee);
    cout << coffee->getDescription() << " " << coffee->getCost() << endl;
    coffee = new Caramel(coffee);
    cout << coffee->getDescription() << " " << coffee->getCost() << endl;

    return 0;
}