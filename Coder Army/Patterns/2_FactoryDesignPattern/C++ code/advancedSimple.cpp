#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

// Abstract Product
class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

// Concrete Products
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

// OCP-friendly Factory with Registration (Raw Pointer version)
class BurgerFactory
{
private:
    unordered_map<string, function<Burger *()>> creators;

public:
    void registerBurger(const string &type, function<Burger *()> creator)
    {
        creators[type] = creator;
    }

    Burger *create(const string &type)
    {
        auto it = creators.find(type);
        if (it != creators.end())
        {
            return it->second(); // Call the creator function
        }
        return nullptr;
    }
};

int main()
{
    BurgerFactory factory;

    // Registration
    factory.registerBurger("Basic", []()
                           { return new BasicBurger(); });
    factory.registerBurger("Standard", []()
                           { return new StandardBurger(); });
    factory.registerBurger("Premium", []()
                           { return new PremiumBurger(); });

    string type = "Standard";
    Burger *burger = factory.create(type);

    if (burger)
        burger->prepare();
    else
        cout << "Unknown burger type!\n";

    delete burger; // Don't forget to delete the created burger to prevent memory leak

    return 0;
}
