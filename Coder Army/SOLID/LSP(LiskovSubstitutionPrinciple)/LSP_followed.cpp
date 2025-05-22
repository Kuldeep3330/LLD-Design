#include <bits/stdc++.h>
using namespace std;

class DepositOnlyAccount
{
public:
    virtual void deposit(int amount) = 0;
};
class Account : public DepositOnlyAccount
{
public:
    virtual void withdraw(int amount) = 0;
};

class SavingAccount : public Account
{
private:
    int balance;

public:
    SavingAccount() : balance(0) {}
    void deposit(int amount) override
    {
        balance += amount;
        cout << "Deposited: " << amount << " in the saving Account, New Balance: " << balance << endl;
    }

    void withdraw(int amount) override
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
    CurrentAccount() : balance(0) {}
    void deposit(int amount) override
    {
        balance += amount;
        cout << "Deposited: " << amount << " in the current Account, New Balance: " << balance << endl;
    }

    void withdraw(int amount) override
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
class FixedAccount : public DepositOnlyAccount
{
private:
    int balance;

public:
    FixedAccount() : balance(0) {}
    void deposit(int amount) override
    {
        balance += amount;
        cout << "Deposited: " << amount << " in the fixed Account, New Balance: " << balance << endl;
    }
};

class BankClient
{
private:
    vector<DepositOnlyAccount *> depositAccounts;
    vector<Account *> withdrawlAccounts;

public:
    BankClient(vector<DepositOnlyAccount *> depositAccounts,
               vector<Account *> withdrawlAccounts) : depositAccounts(depositAccounts), withdrawlAccounts(withdrawlAccounts) {}

    void processTransactions()
    {
        for (Account *acc : withdrawlAccounts)
        {
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for (DepositOnlyAccount *acc : depositAccounts)
        {
            acc->deposit(5000);
        }
    }
};

int main()
{
    vector<Account *> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());

    vector<DepositOnlyAccount *> depositAccounts;
    depositAccounts.push_back(new FixedAccount());

    BankClient *client = new BankClient(depositAccounts, accounts);
    client->processTransactions();

    for (Account *acc : accounts)
    {
        delete acc;
    }
    for (DepositOnlyAccount *acc : depositAccounts)
    {
        delete acc;
    }
    delete client;
    return 0;
}