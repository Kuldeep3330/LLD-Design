#include <bits/stdc++.h>
using namespace std;

class Animal
{
};
class Dog : public Animal
{
};

class Parent
{
public:
    virtual Animal *getAnimal()
    {
        cout << "Parent return animal instance" << endl;
        return new Animal();
    }
};

class Child : public Parent
{
public:
    Animal *getAnimal()
    {
        cout << "Child return dog instance" << endl;
        return new Dog();
    }
};
class Client
{
private:
    Parent *p;

public:
    Client(Parent *p) : p(p) {}

    void takeAnimal()
    {
        p->getAnimal();
    }
};
int main()
{
    Parent *parent = new Parent();
    Child *child = new Child();
    Client *client = new Client(child);
    client->takeAnimal();

    return 0;
}