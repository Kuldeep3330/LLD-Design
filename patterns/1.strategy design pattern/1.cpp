#include <bits/stdc++.h>
using namespace std;

// // strategy design pattern
class PaymentStrategy
{
public:
    virtual void pay(int amout) = 0;
    virtual ~PaymentStrategy() = default;
};
// // concrete strategy 1
class CreditCard : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        cout << "Paid " << amount << " using credit card\n";
    }
};

// // concrete strategy 2
class PayTm : public PaymentStrategy
{
public:
    void pay(int amount) override
    {
        cout << "Paid " << amount << " using PayTm\n";
    }
};
// context class
// PaymentContext is a high-level module (defines how payment is processed).
// whereas CreditCard, PayTm are low-level modules (define specific ways of payment).
// DIP
// High-level modules should not depend on low-level modules. Both should depend on abstractions.
class PaymentContext
{
private:
    PaymentStrategy *strategy;

public:
    PaymentContext(PaymentStrategy *strategy) : strategy(strategy) {}
    void setStretgy(PaymentStrategy *strategy)
    {
        this->strategy = strategy;
    }
    void pay(int amount)
    {
        strategy->pay(amount);
    }
};
int main()
{
    CreditCard creditCard;
    PayTm payTm;
    PaymentContext paymentContext(&creditCard);
    paymentContext.pay(1000); // Paying with credit card
    return 0;
}