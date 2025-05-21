#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
    virtual void deposit(int amount) = 0;
    virtual void withdraw(int amount) = 0;
};

class SavingAccount : public Account
{
private:
    int balance;

public:
    SavingAccount()
    {
        balance = 0;
    }
    void deposit(int amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in the saving Account, New Balance: " << balance << endl;
    }

    void withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from the saving Accouint. new Balance: " << balance << endl;
        }
        else
        {
            cout << "not enough balance in saving account\n";
        }
    }
};
class CurrentAccount : public Account
{
private:
    int balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }
    void deposit(int amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in the current Account, New Balance: " << balance << endl;
    }

    void withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from the current Accouint. new Balance: " << balance << endl;
        }
        else
        {
            cout << "not enough balance in current account\n";
        }
    }
};
class FixedAccount : public Account
{
private:
    int balance;

public:
    FixedAccount()
    {
        balance = 0;
    }
    void deposit(int amount)
    {
        balance += amount;
        cout << "Deposited: " << amount << " in the fixed Account, New Balance: " << balance << endl;
    }

    void withdraw(int amount)
    {
        throw logic_error("Withdrawl is not allowed!");
    }
};

class BankClient
{
private:
    vector<Account *> accounts;

public:
    BankClient(vector<Account *> accounts) : accounts(accounts) {}

    void processTransactions()
    {
        for (Account *acc : accounts)
        {
            acc->deposit(1000);
            // assuming all accounts support withdrawl

            try
            {
                acc->withdraw(500);
            }
            catch (const logic_error &e)
            {
                cout << "Exception: " << e.what() << endl;
            }
        }
    }
};

int main()
{
    vector<Account *> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedAccount());

    BankClient *client = new BankClient(accounts);
    client->processTransactions();
    return 0;
}