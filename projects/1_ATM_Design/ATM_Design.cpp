#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

class BankAccount;
class User;
class ATMState;

// Enums for Operation and Cash Denomination Types
enum OperationType
{
    DISPLAY_BALANCE,
    WITHDRAW_BALANCE
};
enum Denomination
{
    FIFTY = 50,
    HUNDRED = 100,
    FIVE_HUNDRED = 500,
    THOUSAND = 1000
};

// ATMCard Class
class ATMCard
{
private:
    int uuid;
    BankAccount *bankAccount;
    int expiryDate;
    int pin;

public:
    ATMCard(int uuid, BankAccount *bankAccount, int expiryDate, int pin)
        : uuid(uuid), bankAccount(bankAccount), expiryDate(expiryDate), pin(pin) {}

    bool isCorrectPin(int enteredPin)
    {
        return this->pin == enteredPin;
    }

    BankAccount *getBankAccount()
    {
        return bankAccount;
    }
};

// BankAccount Class
class BankAccount
{
private:
    User *user;
    int uuid;
    int balance;

public:
    BankAccount(User *user, int uuid, int balance)
        : user(user), uuid(uuid), balance(balance) {}

    int getBalance() const
    {
        return balance;
    }

    bool withdraw(int amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            return true;
        }
        return false;
    }

    void deposit(int amount)
    {
        balance += amount;
    }
};

// ATMMachine Class
class ATMMachine
{
private:
    int balance;
    map<Denomination, int> cashCount; // Denominations and their counts
    ATMState *currState;

public:
    ATMMachine(int fiftyNotes, int hundredNotes, int fiveHundredNotes, int thousandNotes, ATMState *currState)
        : currState(currState)
    {
        cashCount[FIFTY] = fiftyNotes;
        cashCount[HUNDRED] = hundredNotes;
        cashCount[FIVE_HUNDRED] = fiveHundredNotes;
        cashCount[THOUSAND] = thousandNotes;
        balance = fiftyNotes * FIFTY + hundredNotes * HUNDRED + fiveHundredNotes * FIVE_HUNDRED + thousandNotes * THOUSAND;
    }

    void setCurrentState(ATMState *state)
    {
        delete currState; // Avoid memory leaks
        currState = state;
    }

    int getBalance() const
    {
        return balance;
    }

    bool withdrawCash(int amount)
    {
        if (balance < amount)
            return false;

        map<Denomination, int> tempCashCount = cashCount;
        int tempAmount = amount;

        // Deduct cash starting from the largest denomination
        for (auto it = tempCashCount.rbegin(); it != tempCashCount.rend(); ++it)
        {
            Denomination denom = it->first;
            int &count = it->second;

            int notesNeeded = tempAmount / denom;
            int notesToDeduct = min(notesNeeded, count);

            tempAmount -= notesToDeduct * denom;
            count -= notesToDeduct;
        }

        if (tempAmount == 0)
        {
            cashCount = tempCashCount;
            balance -= amount;
            return true;
        }

        return false;
    }
};

// User Class
class User
{
private:
    string name;
    string address;

public:
    User(string name, string address) : name(name), address(address) {}

    string getName() const { return name; }
    string getAddress() const { return address; }
};

//////////////// State Classes

class ATMState
{
public:
    virtual void insertCard(ATMMachine *atmMachine, ATMCard *atmCard)
    {
        cout << "Operation not allowed in the current state.\n";
    }
    virtual void authenticatePin(ATMMachine *atmMachine, ATMCard *atmCard, int pin)
    {
        cout << "Operation not allowed in the current state.\n";
    }
    virtual void selectOperations(ATMMachine *atmMachine, ATMCard *atmCard, OperationType operationType)
    {
        cout << "Operation not allowed in the current state.\n";
    }
    virtual void cashWithdrawal(ATMMachine *atmMachine, ATMCard *atmCard, int amount)
    {
        cout << "Operation not allowed in the current state.\n";
    }
    virtual void displayBalance(ATMMachine *atmMachine, ATMCard *atmCard)
    {
        cout << "Operation not allowed in the current state.\n";
    }
    virtual void ejectCard(ATMMachine *atmMachine)
    {
        cout << "Operation not allowed in the current state.\n";
    }
};

class IdleState : public ATMState
{
public:
    void insertCard(ATMMachine *atmMachine, ATMCard *atmCard) override
    {
        cout << "Card inserted successfully.\n";
        atmMachine->setCurrentState(new HasCardState());
    }
};

class HasCardState : public ATMState
{
public:
    void authenticatePin(ATMMachine *atmMachine, ATMCard *atmCard, int pin) override
    {
        if (atmCard->isCorrectPin(pin))
        {
            cout << "Pin authenticated successfully.\n";
            atmMachine->setCurrentState(new SelectOperationState());
        }
        else
        {
            cout << "Incorrect pin. Try again.\n";
        }
    }

    void ejectCard(ATMMachine *atmMachine) override
    {
        cout << "Card ejected.\n";
        atmMachine->setCurrentState(new IdleState());
    }
};

class SelectOperationState : public ATMState
{
public:
    void selectOperations(ATMMachine *atmMachine, ATMCard *atmCard, OperationType operationType) override
    {
        switch (operationType)
        {
        case DISPLAY_BALANCE:
            atmMachine->setCurrentState(new CheckBalanceState());
            break;
        case WITHDRAW_BALANCE:
            atmMachine->setCurrentState(new CashWithdrawalState());
            break;
        default:
            cout << "Invalid operation selected.\n";
        }
    }

    void ejectCard(ATMMachine *atmMachine) override
    {
        cout << "Card ejected.\n";
        atmMachine->setCurrentState(new IdleState());
    }
};

class CheckBalanceState : public ATMState
{
public:
    void displayBalance(ATMMachine *atmMachine, ATMCard *atmCard) override
    {
        cout << "Current balance: " << atmCard->getBankAccount()->getBalance() << "\n";
        atmMachine->setCurrentState(new IdleState());
    }

    void ejectCard(ATMMachine *atmMachine) override
    {
        cout << "Card ejected.\n";
        atmMachine->setCurrentState(new IdleState());
    }
};

class CashWithdrawalState : public ATMState
{
public:
    void cashWithdrawal(ATMMachine *atmMachine, ATMCard *atmCard, int amount) override
    {
        if (atmCard->getBankAccount()->withdraw(amount))
        {
            if (atmMachine->withdrawCash(amount))
            {
                cout << "Successfully withdrew " << amount << ".\n";
            }
            else
            {
                cout << "ATM has insufficient cash.\n";
                atmCard->getBankAccount()->deposit(amount);
            }
        }
        else
        {
            cout << "Insufficient balance in your account.\n";
        }
        atmMachine->setCurrentState(new IdleState());
    }

    void ejectCard(ATMMachine *atmMachine) override
    {
        cout << "Card ejected.\n";
        atmMachine->setCurrentState(new IdleState());
    }
};

//////////////// Driver Code
// void ATMMachine::setCurrentState(ATMState *state)
// {
//     delete currState; // Avoid memory leaks
//     currState = state;
// }

int main()
{
    User user("John Doe", "123 Street, City");
    BankAccount account(&user, 1001, 5000);
    ATMCard card(101, &account, 20251231, 1234);

    ATMMachine atm(10, 10, 10, 10, new IdleState());

    atm.setCurrentState(new IdleState());
    ATMState state;

    state.insertCard(&atm, &card);
    state.authenticatePin(&atm, &card, 1234);
    state.selectOperations(&atm, &card, WITHDRAW_BALANCE);
    state.cashWithdrawal(&atm, &card, 1000);

    return 0;
}
