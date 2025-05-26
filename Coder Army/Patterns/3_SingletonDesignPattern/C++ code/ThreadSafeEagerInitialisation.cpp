#include <iostream>
using namespace std;
// singleton

class Singleton
{
private:
    static Singleton *instance;
    Singleton()
    {
        cout << "Singleton constructor called , new instance  created!\n";
    }

public:
    static Singleton *getInstance()
    {
        return instance;
    }
};

Singleton *Singleton::instance = new Singleton();

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}