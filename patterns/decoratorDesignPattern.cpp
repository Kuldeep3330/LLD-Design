#include <iostream>
#include <string>

using namespace std;
// //coffee customization
// class Coffee
// {
// public:
//     virtual string getDescription() const = 0;
//     virtual int getCost() const = 0;
//     virtual ~Coffee() = default;
// };
// // simplecoffee is a coffee
// class SimpleCoffee : public Coffee
// {
// public:
//     string getDescription() const override
//     {
//         return "simple coffee";
//     }
//     int getCost() const override
//     {
//         return 10;
//     }
// };

// // decorator
// //  means coffeeDecorator is a coffee and coffeedecorator has a coffee
// class CoffeeDecorator : public Coffee
// {
// protected:
//     Coffee *coffee;

// public:
//     CoffeeDecorator(Coffee *coffee) : coffee(coffee) {}
//     string getDescription() const override
//     {
//         return coffee->getDescription();
//     }
//     int getCost() const override
//     {
//         return coffee->getCost();
//     }
//     virtual ~CoffeeDecorator()
//     {
//         delete coffee;
//     }
// };
// // concrete decorator
// class Milk : public CoffeeDecorator
// {
// public:
//     Milk(Coffee *coffee) : CoffeeDecorator(coffee) {}
//     string getDescription() const override
//     {
//         return coffee->getDescription() + " Milk";
//     }
//     int getCost() const override
//     {
//         return coffee->getCost() + 10;
//     }
// };
// class Caramel : public CoffeeDecorator
// {
// public:
//     Caramel(Coffee *coffee) : CoffeeDecorator(coffee) {}
//     string getDescription() const override
//     {
//         return coffee->getDescription() + " caramel";
//     }
//     int getCost() const override
//     {
//         return coffee->getCost() + 20;
//     }
// };

// pizza customization
class Pizza
{
public:
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Pizza() = default;
};
// concrete component
class PlainPizza : public Pizza
{
public:
    string getDescription() const override
    {
        return "plain pizza";
    }
    double getCost() const override
    {
        return 10.0;
    }
};
// Decorator
class PizzaDecorator : public Pizza
{
protected:
    Pizza *pizza;

public:
    PizzaDecorator(Pizza *pizza) : pizza(pizza) {}
    string getDescription() const override
    {
        return pizza->getDescription();
    }
    double getCost() const override
    {
        return pizza->getCost();
    }
    virtual ~PizzaDecorator()
    {
        delete pizza;
    }
};
// concrete decorators
class Cheese : public PizzaDecorator
{
private:
public:
    Cheese(Pizza *pizza) : PizzaDecorator(pizza) {}
    string getDescription() const override
    {
        return pizza->getDescription() + ", Cheese";
    }
    double getCost() const override
    {
        return pizza->getCost() + 20.0;
    }
};
class Mushroom : public PizzaDecorator
{
private:
public:
    Mushroom(Pizza *pizza) : PizzaDecorator(pizza) {}
    string getDescription() const override
    {
        return pizza->getDescription() + ", Mushroom";
    }
    double getCost() const override
    {
        return pizza->getCost() + 20.0;
    }
};
int main()
{
    Pizza *pizza = new PlainPizza();
    cout << pizza->getDescription() << " : " << pizza->getCost() << " INR" << endl;

    // Add cheese
    pizza = new Cheese(pizza);
    cout << pizza->getDescription() << " : " << pizza->getCost() << " INR" << endl;

    // Add mushrooms
    pizza = new Mushroom(pizza);
    cout << pizza->getDescription() << " : " << pizza->getCost() << " INR" << endl;
    delete pizza;
    // Coffee *coffee = new SimpleCoffee();
    // cout << coffee->getDescription() << " " << coffee->getCost() << endl;
    // coffee = new Milk(coffee);
    // cout << coffee->getDescription() << " " << coffee->getCost() << endl;
    // coffee = new Caramel(coffee);
    // cout << coffee->getDescription() << " " << coffee->getCost() << endl;

    return 0;
}