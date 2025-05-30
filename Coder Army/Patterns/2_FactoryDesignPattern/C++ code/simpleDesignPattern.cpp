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

class SimpleFactory
{
public:
    Burger *create(const string &type)
    {
        if (type == "Basic")
        {
            return new BasicBurger();
        }
        else if (type == "Standard")
        {
            return new StandardBurger();
        }
        else if (type == "Premium")
        {
            return new PremiumBurger();
        }
        else
        {
            return nullptr;
        }
    }
};
int main()
{
    string type = "Standard";

    SimpleFactory *factory = new SimpleFactory();
    Burger *burger = factory->create(type);
    burger->prepare();
    delete factory;
    delete burger;

    return 0;
}