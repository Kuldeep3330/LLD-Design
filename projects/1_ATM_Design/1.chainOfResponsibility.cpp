#include <iostream>
#include <memory>
using namespace std;

// chain of responsibility
class Handler
{
protected:
    Handler *nextHandler;

public:
    // Handler() : nextHandler(nullptr) {}
    void setNextHandler(Handler *handler)
    {
        nextHandler = handler;
    }
    virtual void handleRequest(int amount) = 0;
    virtual ~Handler() = default;
};
// FiveHundredRupeesHandler
class FiveHundredRupeesHandler : public Handler
{
public:
    void handleRequest(int amount) override
    {
        if (amount >= 500)
        {
            int notes = amount / 500;
            amount = amount - (notes * 500);
            cout << "Five hundred rupees of notes: " << notes << "\n";
        }
        if (nextHandler)
        {
            nextHandler->handleRequest(amount);
        }
    }
};
// OneHundredRupeesHandler
class OneHundredRupeesHandler : public Handler
{
public:
    void handleRequest(int amount) override
    {
        if (amount >= 100)
        {
            int notes = amount / 100;
            amount = amount - (notes * 100);
            cout << "One hundred rupees of notes: " << notes << "\n";
        }
        if (nextHandler)
        {
            nextHandler->handleRequest(amount);
        }
    }
};
// FiftyRupeesHandler
class FiftyRupeesHandler : public Handler
{
public:
    void handleRequest(int amount) override
    {
        if (amount >= 50)
        {
            int notes = amount / 50;
            amount = amount - (notes * 50);
            cout << "Fifty rupees of notes: " << notes << "\n";
        }
        if (nextHandler)
        {
            nextHandler->handleRequest(amount);
        }
    }
};
// TenRupeesHandler
class TenRupeesHandler : public Handler
{
public:
    void handleRequest(int amount) override
    {
        if (amount >= 10)
        {
            int notes = amount / 10;
            amount = amount - (notes * 10);
            cout << "Ten rupees of notes: " << notes << "\n";
        }
        if (nextHandler)
        {
            nextHandler->handleRequest(amount);
        }
    }
};
int main()
{
    Handler *fiveHundredRupeesHandler = new FiveHundredRupeesHandler();
    Handler *oneHundredRupeesHandler = new OneHundredRupeesHandler();
    Handler *fiftyRupeesHandler = new FiftyRupeesHandler();
    Handler *tenRupeesHandler = new TenRupeesHandler();
    fiveHundredRupeesHandler->setNextHandler(oneHundredRupeesHandler);
    oneHundredRupeesHandler->setNextHandler(fiftyRupeesHandler);
    fiftyRupeesHandler->setNextHandler(tenRupeesHandler);

    fiveHundredRupeesHandler->handleRequest(2650);

    delete fiveHundredRupeesHandler;
    delete oneHundredRupeesHandler;
    delete fiftyRupeesHandler;
    delete tenRupeesHandler;
    return 0;
}