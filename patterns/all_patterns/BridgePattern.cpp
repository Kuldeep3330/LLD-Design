#include <iostream>
#include <memory>

using namespace std;

// implementation interface
class Device
{
public:
    virtual void powerOn() = 0;
    virtual void powerOff() = 0;
    virtual void setVolume(int volume) = 0;
    virtual ~Device() = default;
};

// concrete implementation 1
class TV : public Device
{
public:
    void powerOn() override
    {
        cout << "TV is now ON\n";
    }
    void powerOff() override
    {
        cout << "TV is now off\n";
    }
    void setVolume(int volume)
    {
        cout << "TV volume is up by " << volume << "\n";
    }
};

// concrete implementation 2
class Radio : public Device
{
public:
    void powerOn() override
    {
        cout << "Radio is now ON\n";
    }
    void powerOff() override
    {
        cout << "Radio is now off\n";
    }
    void setVolume(int volume)
    {
        cout << "Radio volume is up by " << volume << "\n";
    }
};

// Abstraction
class RemoteControl
{
protected:
    // Device *device;
    shared_ptr<Device> device; // Device *device

public:
    RemoteControl(shared_ptr<Device> device) : device(device) {}
    virtual void togglePower() = 0;
    virtual void changeVolume(int volume) = 0;
    virtual ~RemoteControl() = default;
};

class BasicRemote : public RemoteControl
{
    bool isOn = false;

public:
    BasicRemote(shared_ptr<Device> device) : RemoteControl(device) {}
    void togglePower() override
    {
        if (isOn)
        {
            device->powerOff();
        }
        else
        {
            device->powerOn();
        }
        isOn = !isOn;
    }
    void changeVolume(int volume) override
    {
        device->setVolume(volume);
    }
};

// refined abstraction2
class AdvancedRemote : public RemoteControl
{
public:
    AdvancedRemote(shared_ptr<Device> device) : RemoteControl(device) {}
    void togglePower() override
    {
        cout << "Advanced remote toggling power \n";
        device->powerOn();
        device->powerOff();
    }
    void changeVolume(int volume) override
    {
        cout << "Advanced remote volume adjustment\n";
        device->setVolume(volume);
    }
    void mute()
    {
        cout << "Advanced remote muting device.\n";
        device->setVolume(0);
    }
};

int main()
{
    // Device *tv = new TV();
    shared_ptr<Device> tv = make_shared<TV>();
    // Device *radio = new Radio();
    shared_ptr<Device> radio = make_shared<Radio>();
    // BasicRemote *bremote = new BasicRemote(tv);
    BasicRemote bremote(tv);
    // AdvancedRemote *aremote = new AdvancedRemote(radio);
    AdvancedRemote aremote(radio);
    bremote.togglePower();
    bremote.changeVolume(9);

    aremote.togglePower();
    aremote.changeVolume(15);
    aremote.mute();
    return 0;
}
