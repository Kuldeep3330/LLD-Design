    // 1.Class Invariant of a parent class Object should not be broken by
//  child class Object.
    // Hence child class can either maintain or strengthen the invariant 
// but never narrows it down.


/*"Objects of a superclass should be replaceable with objects of its subclass without altering the correctness of the program." */
// Invariant : Balance cannot be negative
class BankAccount {
  constructor(balance) {
    if (balance < 0) {
      throw new Error("Balance can't be negative");
    }
    this.balance = balance;
  }

  withdraw(amount) {
    if (this.balance - amount < 0) {
      throw new Error("Insufficient funds");
    }
    this.balance -= amount;
    console.log(`Amount withdrawn. Remaining balance is ${this.balance}`);
  }
}

class CheatAccount extends BankAccount {
  withdraw(amount) {
    // Violates invariant: allows negative balance
    this.balance -= amount;
    console.log(`Amount withdrawn. Remaining balance is ${this.balance}`);
  }
}

const account = new BankAccount(100);
account.withdraw(100);

// const cheat = new CheatAccount(100);
// cheat.withdraw(150); // This would allow negative balance: -50
