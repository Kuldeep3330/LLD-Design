#include <bits/stdc++.h>
using namespace std;
// command interface
class Command
{
public:
    virtual void execute() = 0;
};
// Reciever
class Light
{
public:
    void turnOn()
    {
        cout << "Light ON" << endl;
    }
    void turnOff()
    {
        cout << "Light OFF" << endl;
    }
};
class TurnOnLightCommand : public Command
{
private:
    Light light;

public:
    TurnOnLightCommand(Light light) : light(light) {}
    void execute() override { light.turnOn(); }
};

class TurnOffLightCommand : public Command
{
private:
    Light light;

public:
    TurnOffLightCommand(Light light) : light(light) {}
    void execute() override { light.turnOff(); }
};

// invoker
// class RemoteControl
// {
// private:
//     vector<Command *> commands;

// public:
//     void addCommands(Command *command)
//     {
//         commands.push_back(command);
//     }
//     void pressButton()
//     {
//         if (!commands.empty())
//         {
//             commands.back()->execute();
//             commands.pop_back();
//         }
//         else
//         {
//             cout << "No more commands\n";
//         }
//     }
// };

// class RemoteControl{
//     private:
//     Command command;
//     public
// };
int main()
{
    Light roomLight;
    // create commands
    TurnOnLightCommand *lightOn = new TurnOnLightCommand(roomLight);
    TurnOffLightCommand *lightOff = new TurnOffLightCommand(roomLight);
    RemoteControl remote;
    remote.addCommands(lightOn);
    remote.addCommands(lightOff);
    remote.pressButton();
    remote.pressButton();
    remote.pressButton();
    return 0;
}