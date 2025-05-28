#include <iostream>
#include <vector>
using namespace std;
class Component
{
public:
    virtual void showDetails() = 0;
};
class Leaf : public Component
{
private:
    string name;

public:
    Leaf(const string &name) : name(name) {}
    void showDetails() override
    {
        cout << "leaf : " << name << "\n ";
    }
};
class Composite : public Component
{
private:
    vector<Component *> childrens;

public:
    void add(Component *children)
    {
        childrens.push_back(children);
    }
    void showDetails()
    {
        for (auto it : childrens)
        {
            it->showDetails();
        }
    }
};
int main()
{
    Leaf *leaf1 = new Leaf("Leaf 1");
    Leaf *leaf2 = new Leaf("Leaf 2");
    Composite *composite = new Composite();
    composite->add(leaf1);
    composite->add(leaf2);
    composite->showDetails();
    return 0;
}