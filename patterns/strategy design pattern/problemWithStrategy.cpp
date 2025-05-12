#include <bits/stdc++.h>
using namespace std;

// strategy design pattern
//  it is a behavioral dP that enables selecting an algorithm's behavior at runtime.

// without strategy pattern
class PaymentContext
{
public:
    void pay(const string &paymentType)
    {
        if (paymentType == "creditCard")
        {
            cout << "Paying with credit card" << endl;
        }
        else if (paymentType == "paypal")
        {
            cout << "Paying with paypal" << endl;
        }
        else
        {
            cout << "Invalid payment type" << endl;
        }
    }
};

int main()
{
    PaymentContext paymentContext;
    paymentContext.pay("creditCard");

    return 0;
}