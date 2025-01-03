#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// When you have multiple algorithms for a specific task and want to select one at runtime.
// to avoid using many conditional statements
// to encapsulate algorithm in separate classes to make them easier to maintain and test
// payment processing system
// Imagine you have a payment processing system where users can choose between Credit Card, Paytm, or cash as payment methods.
// here we have multiple payment strategy
// 1.Define the strategy
// class PaymentStrategy
// {
// public:
//     virtual void pay(int amount) = 0; // pure virtual function
//     virtual ~PaymentStrategy() = default;
// };
// // 2. Implement Concrete Strategies
// class CreditCard : public PaymentStrategy
// {
// private:
//     string name;
//     string cardNumber;
// public:
//     CreditCard(const string &name, const string &cardNumber) : name(name), cardNumber(cardNumber) {}
//     void pay(int amount) override
//     {
//         cout << amount << " paid using the credit card number: " << cardNumber << endl;
//     }
// };
// // startegy 2
// class PayTm : public PaymentStrategy
// {
// private:
//     string UPIid;
// public:
//     PayTm(const string &UPIid) : UPIid(UPIid) {}
//     void pay(int amount) override
//     {
//         cout << amount << " paid using the UPI ID: " << UPIid << endl;
//     }
// };
// // strategy 3
// class Cash : public PaymentStrategy
// {
// public:
//     void pay(int amount)
//     {
//         cout << amount << " paid by cash !😎" << endl;
//     }
// };

// // createing the context class which will use the startegy
// class PaymentContext
// {
// private:
//     PaymentStrategy *strategy;
// public:
//     PaymentContext(PaymentStrategy *strategy) : strategy(strategy) {}
//     void setStrategy(PaymentStrategy *strategy)
//     {
//         this->strategy = strategy;
//     }
//     void executePayment(int amount)
//     {
//         strategy->pay(amount);
//     }
// };

// Sorting Algorithm
// Define the strategy Interface
class SortingStartegy
{
public:
    virtual void sort(vector<int> &v) = 0;
    virtual ~SortingStartegy() = default;
};
// implementing concrete strategies
// strategy 1
class BubbleSort : public SortingStartegy
{
public:
    void sort(vector<int> &data) override
    {
        for (int i = 0; i < data.size() - 1; i++)
        {
            for (int j = 0; j < data.size() - 1; j++)
            {
                if (data[j] > data[j + 1])
                {
                    swap(data[j], data[j + 1]);
                }
            }
        }
        cout << "sorted data using Bubble sort\n";
    }
};
// strategy 2
class QuickSort : public SortingStartegy
{
public:
    void sort(vector<int> &data) override
    {
        cout << "data got sorted using Quick sort\n";
    }
};
// create context class
class SortContext
{
private:
    SortingStartegy *strategy;

public:
    SortContext(SortingStartegy *strategy) : strategy(strategy) {}
    void setStrategy(SortingStartegy *strategy)
    {
        this->strategy = strategy;
    }
    void executeSort(vector<int> &data)
    {
        strategy->sort(data);
    }
};
int main()
{
    // client code for sorting
    vector<int> data = {23, 6, 4, 54, 21, 1};
    SortingStartegy *bubbleSort = new BubbleSort();
    SortingStartegy *quickSort = new QuickSort();
    SortContext *context;
    context = new SortContext(bubbleSort);
    context->executeSort(data);
    delete context;
    delete quickSort;
    delete bubbleSort;

    // //client code for payment
    // PaymentStrategy *cash = new Cash();
    // PaymentStrategy *creditCard = new CreditCard("kuldeep", "7986");
    // PaymentStrategy *payTm = new PayTm("2358983@ybl");
    // PaymentContext *context;
    // context = new PaymentContext(cash);
    // context->executePayment(20);
    // delete context;
    // delete payTm;
    // delete creditCard;
    // delete cash;

    return 0;
}