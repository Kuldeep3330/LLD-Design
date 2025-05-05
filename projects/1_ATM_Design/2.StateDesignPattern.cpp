#include <iostream>
using namespace std;

class PhoneState
{
public:
    virtual void pressButton() = 0;
    virtual ~PhoneState() = default;
};
class OnPhoneState : public PhoneState
{
public:
    void pressButton() override
    {
        cout << "Phone is in Off state!" << "\n";
    }
};
class OffPhoneState : public PhoneState
{
public:
    void pressButton() override
    {
        cout << "Phone is in On state!" << "\n";
    }
};
class Phone
{
private:
    PhoneState *state;

public:
    Phone(PhoneState *state) : state(state) {}
    void setState(PhoneState *state)
    {
        this->state = state;
    }
    void show()
    {
        state->pressButton();
    }
};
int main()
{
    PhoneState *onPhoneState = new OnPhoneState();
    PhoneState *offPhoneState = new OffPhoneState();
    Phone *phone = new Phone(onPhoneState);
    phone->show();
    phone->setState(offPhoneState);
    phone->show();
    delete onPhoneState;
    delete offPhoneState;
    delete phone;

    return 0;
}