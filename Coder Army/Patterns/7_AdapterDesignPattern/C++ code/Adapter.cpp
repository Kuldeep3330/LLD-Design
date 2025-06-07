#include <bits/stdc++.h>
using namespace std;

/*
Voltage Adapter
Scenario:
A device (like a laptop charger) operates at 120V, but your power source supplies 240V. Use an adapter to convert the voltage.
*/
// Target Interface
class VoltageDevice
{
public:
    virtual void useDevice() const = 0;
    virtual ~VoltageDevice() = default;
};
// 2. Adaptee
class HighVoltage
{
public:
    void supplyHighVoltage() const
    {
        cout << "Supplying 240V power " << endl;
    }
};
// 3. Adapter
class VoltageAdapter : public VoltageDevice
{
private:
    HighVoltage *highVoltage;

public:
    VoltageAdapter(HighVoltage *highVoltage) : highVoltage(highVoltage) {}
    void useDevice() const override
    {
        cout << "Converting 240V to 120V for the device." << endl;
        highVoltage->supplyHighVoltage();
    }
};
int main()
{
    // client code for voltage adapter
    HighVoltage *highVoltage = new HighVoltage();
    VoltageDevice *adapter = new VoltageAdapter(highVoltage);

    adapter->useDevice();

    delete adapter;
    delete highVoltage;
    return 0;
}