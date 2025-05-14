#include <bits/stdc++.h>
using namespace std;

class Observer
{
public:
    virtual void update(int temperature) = 0;
    virtual ~Observer() = default;
};

class Subject
{ // observable
public:
    virtual void registerObserver(Observer *observer) = 0;
    virtual void removeObserver(Observer *observer) = 0;
    virtual void notifyObservers(int temperature) = 0;
    virtual ~Subject() = default;
};

class WeatherStation : public Subject
{
private:
    vector<Observer *> observers;
    int temperature;

public:
    void registerObserver(Observer *observer) override
    {
        observers.push_back(observer);
    }
    void removeObserver(Observer *observer) override
    {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }
    void notifyObservers(int temperature) override
    {
        for (auto observer : observers)
        {
            observer->update(temperature);
        }
    }
};

// observers can be any class that implements the Observer interface
// ie