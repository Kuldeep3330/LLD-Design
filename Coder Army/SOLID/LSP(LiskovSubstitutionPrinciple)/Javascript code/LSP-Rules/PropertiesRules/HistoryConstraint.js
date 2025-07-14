// Sub class methods should not be allowed state changes What
// Base class never allowed.

/* violation of LSP, LSP says: You should be able to replace an object of a base type with an object of a derived type without breaking correctness of the program. */
class BankAccount {
  constructor(balance) {
    if (balance < 0) throw new Error("Balance can't be negative");
    this.balance = balance;
  }

  withdraw(amount) {
    if (this.balance - amount < 0) throw new Error("Insufficient funds");
    this.balance -= amount;
    console.log(`Amount withdrawn. Remaining balance is ${this.balance}`);
  }
}

class FixedDepositAccount extends BankAccount {
  withdraw(amount) {
    throw new Error("Withdraw not allowed in Fixed Deposit");
  }
}

const account = new BankAccount(100);
account.withdraw(50);

// const fdAccount = new FixedDepositAccount(100);
// fdAccount.withdraw(50); // Error: Withdraw not allowed in Fixed Deposit
