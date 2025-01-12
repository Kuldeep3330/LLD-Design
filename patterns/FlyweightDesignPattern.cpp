#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
// flyweight Interface(defines the interface for shared objects)
class Character
{
public:
    virtual void display(int x, int y) const = 0; // extrinsic state:position
    virtual ~Character() = default;
};
// 2. Concrete Flyweight(implements the flyweight and stores intrinsic data)
class ConcreteCharacter : public Character
{
private:
    char symbol; // intrinsic state
    string font; // intrinsic state
public:
    ConcreteCharacter(char symbol, const string &font) : symbol(symbol), font(font) {}
    void display(int x, int y) const override
    {
        cout << "Character: " << symbol << ", font: " << font << ", position: ( " << x << ", " << y << " )" << endl;
    }
};
// flyweight factory(manage the pool of shared data)
class CharacterFactory
{
private:
    unordered_map<char, Character *> pool;

public:
    Character *getCharacter(char symbol, const string &font)
    {
        if (pool.find(symbol) == pool.end())
        {
            pool[symbol] = new ConcreteCharacter(symbol, font);
        }
        return pool[symbol];
    }
    ~CharacterFactory()
    {
        for (auto &pair : pool)
        {
            delete pair.second;
        }
    }
};
// client code
int main()
{
    CharacterFactory factory;
    Character *c1 = factory.getCharacter('A', "Arial");
    Character *c2 = factory.getCharacter('B', "Arial");
    Character *c3 = factory.getCharacter('A', "Arial");
    c1->display(10, 20); // Display at position (10, 20)
    c2->display(30, 40); // Display at position (30, 40)
    c3->display(50, 60); // Display at position (50, 60)

    // Confirm shared instances
    cout << "c1 and c3 are " << ((c1 == c3) ? "the same instance." : "different instances.") << endl;
}
