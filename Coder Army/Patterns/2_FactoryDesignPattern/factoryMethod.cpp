#include <bits/stdc++.h>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() {}
};

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Basic burger\n";
    }
};
class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Standard burger\n";
    }
};
class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Premium burger\n";
    }
};

class Factory
{
public:
    virtual Burger *create() = 0;
    virtual ~Factory() {}
};

class BasicBurgerFactory : public Factory
{
public:
    Burger *create() override
    {
        return new BasicBurger();
    }
};
class StandardBurgerFactory : public Factory
{
public:
    Burger *create() override
    {
        return new StandardBurger();
    }
};

int main()
{
    string type = "Standard";
    Factory *factory = nullptr;

    if (type == "Basic")
        factory = new BasicBurgerFactory();
    else if (type == "Standard")
        factory = new StandardBurgerFactory();
    else
    {
        cout << "Unknown burger type.\n";
        return 1;
    }

    Burger *burger = factory->create();
    burger->prepare();

    delete burger;
    delete factory;
    return 0;
}
