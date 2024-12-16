#include <bits/stdc++.h>
using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    Singleton() {}

public:
    // public static method to get instance
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        else
        {
            return instance;
        }
    }
    void dispaly()
    {
        cout << "single instance cretead: " << this << "\n";
    }
};
// intialisation of the static keyword
Singleton *Singleton::instance = nullptr;
int main()
{
    Singleton *s1 = Singleton::getInstance();
    s1->dispaly();
    // Singleton *s2 = Singleton::getInstance();
    // s2->dispaly();
    return 0;
}