#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Air Traffic control
// Mediator Interface
class AirTrafficMediator
{
public:
    virtual void registerPlane(const string &planeName) = 0;
    virtual void notifyTakeoff(const string &planeName) = 0;
    virtual void notifyLanding(const string &planeName) = 0;
    virtual ~AirTrafficMediator() {}
};
// users(colleques)
class Plane
{
private:
    string name;
    AirTrafficMediator *mediator;

public:
    Plane(const string &name, AirTrafficMediator *mediator) : name(name), mediator(mediator) {}

    void takeoff()
    {
        cout << name << " requesting takeoff.\n";
        mediator->notifyTakeoff(name);
    }

    void land()
    {
        cout << name << " requesting landing.\n";
        mediator->notifyLanding(name);
    }

    string getName() const { return name; }
};
// concrete Mediator
class ControlTower : public AirTrafficMediator
{
private:
    vector<string> planes;

public:
    void registerPlane(const string &planeName) override
    {
        planes.push_back(planeName);
        cout << planeName << " registered with the control tower.\n";
    }

    void notifyTakeoff(const string &planeName) override
    {
        cout << "Control Tower: " << planeName << " is cleared for takeoff.\n";
    }

    void notifyLanding(const string &planeName) override
    {
        cout << "Control Tower: " << planeName << " is cleared for landing.\n";
    }
};

int main()
{

    ControlTower tower;

    Plane plane1("Flight 101", &tower);
    Plane plane2("Flight 202", &tower);

    tower.registerPlane(plane1.getName());
    tower.registerPlane(plane2.getName());

    plane1.takeoff();
    plane2.land();

    return 0;
}
