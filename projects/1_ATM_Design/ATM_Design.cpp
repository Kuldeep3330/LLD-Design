#include <bits/stdc++.h>
using namespace std;
class BankAccount;
class User;
class ATMState;
enum OperationType
{
    DISPLAY_BALANCE,  // 0
    WITHDRAW_BALANCE, // 1

};
class ATMCard
{
private:
    int uuid;
    BankAccount *bankAccount;
    int expiryDate;
    int pin;

public:
    ATMCard(int uuid,
            BankAccount *bankAccount,
            int expiryDate,
            int pin) : uuid(uuid), bankAccount(bankAccount), expiryDate(expiryDate), pin(pin) {}

    bool isCorrectPin(int pin)
    {
        return this->pin == pin;
    }
    BankAccount *getBankAccount()
    {
        return bankAccount;
    }
};
class BankAccount
{
private:
    User *user;
    int uuid; // bank account uuid
    int balance;

public:
    BankAccount(User *user,
                int uuid,
                int balance) : user(user), uuid(uuid), balance(balance) {}
    int getBalance()
    {
        return balance;
    }
};
class ATMMachine
{
private:
    int balance;
    int fiftyNotes;
    int hundredNotes;
    int fiveHundredNotes;
    int thousandNotes;
    ATMState *currState;

public:
    ATMMachine(int balance,
               int fiftyNotes,
               int hundredNotes,
               int fiveHundredNotes,
               int thousandNotes,
               ATMState *currState) : fiftyNotes(fiftyNotes), hundredNotes(hundredNotes), fiveHundredNotes(fiveHundredNotes), thousandNotes(thousandNotes), currState(currState)
    {
        balance = fiftyNotes * 50 + hundredNotes * 100 + fiveHundredNotes * 50 + thousandNotes * 100;
    }
    void setCurrentState(ATMState *currState)
    {
        this->currState = currState;
    }
    int getBalance()
    {
        return balance;
    }
};
class User
{
};

////////////////State
class ATMState
{
public:
    virtual void insertCard(ATMMachine *atmMachine, ATMCard *atmCard)
    {
        cout << "it's not allowed\n";
    }
    virtual void authentiacatePin(ATMMachine *atmMachine, ATMCard *atmCard, int pin)
    {
        cout << "it's not allowed\n";
    }
    virtual void selectOperations(ATMMachine *atmMachine, ATMCard *atmCard, OperationType operationType)
    {
        cout << "it's not allowed\n";
    }
    virtual void cashWithdrawal(ATMMachine *atmMachine, ATMCard *atmCard, int amount)
    {
        cout << "it's not allowed\n";
    }
    virtual void displayBalance(ATMMachine *atmMachine, ATMCard *atmCard)
    {
        cout << "it's not allowed\n";
    }
    virtual void ejectCard(ATMMachine *atmMachine)
    {
        cout << "it's not allowed\n";
    }
    // virtual void exit(ATMMachine *atmMachine)
    // {
    //     cout << "it's not allowed\n";
    // }
};
class CashWithddrawalState : public ATMState
{
public:
    void cashWithdrawal(ATMMachine *atmMachine, ATMCard *atmCard, int amount) override
    {
        if (atmCard->getBankAccount()->getBalance() < amount)
        {
            cout << " you not have sufficient balance\n";
        }
        else if (atmMachine->getBalance() < amount)
        {
            cout << " atm not have sufficient balance\n";
        }
        else
        {
            cout << "yout have made the tranction of: " << amount << " rs\n";
        }
        atmMachine->setCurrentState(new IdleState());
    }
    void ejectCard(ATMMachine *atmMachine) override
    {
        cout << "ejected card\n";
        atmMachine->setCurrentState(new IdleState());
    }
    // void exit(ATMMachine *atmMachine) override
    // {
    //     ejectCard(atmMachine);
    // }
};
class CheckBalanceState : public ATMState
{
public:
    void displayBalance(ATMMachine *atmMachine, ATMCard *atmCard) override
    {
        cout << "your available balance is: " << atmCard->getBankAccount()->getBalance();
        atmMachine->setCurrentState(new IdleState());
    }

    void ejectCard(ATMMachine *atmMachine) override
    {
        cout << "ejected card\n";
        atmMachine->setCurrentState(new IdleState());
    }
    // void exit(ATMMachine *atmMachine) override
    // {
    //     ejectCard(atmMachine);
    // }
};
class HasCardState : public ATMState
{
public:
    void authentiacatePin(ATMMachine *atmMachine, ATMCard *atmCard, int pin) override
    {
        if (atmCard->isCorrectPin(pin))
        {
            cout << "successfully authenticated!\n";
            atmMachine->setCurrentState(new SelectOperationState());
        }
        else
        {
            cout << "incorrect pin\n";
        }
    }

    void ejectCard(ATMMachine *atmMachine) override
    {
        cout << "ejected card\n";
        atmMachine->setCurrentState(new IdleState());
    }
    // void exit(ATMMachine *atmMachine) override
    // {
    //     ejectCard(atmMachine);
    // }
};
class IdleState : public ATMState
{
public:
    void insertCard(ATMMachine *atmMachine, ATMCard *atmCard) override
    {
        cout << "Card is inserted successfully\n";
        atmMachine->setCurrentState(new HasCardState());
    }
};
// class MaintenanceState : public ATMState
// {
// public:
// };
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
            atmMachine->setCurrentState(new CashWithddrawalState());
            break;
        default:
            cout << "invalid operation type!\n";
        }
    }
    void ejectCard(ATMMachine *atmMachine) override
    {
        cout << "ejected card\n";
        atmMachine->setCurrentState(new IdleState());
    }
    // void exit(ATMMachine *atmMachine) override
    // {
    //     ejectCard(atmMachine);
    // }
};
//////////Above state
int main()
{
    return 0;
}