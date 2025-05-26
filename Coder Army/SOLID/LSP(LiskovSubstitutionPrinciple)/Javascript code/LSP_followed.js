class DepositOnlyAccount {
  deposit(amount) {
    throw new Error("deposit() must be implemented.");
  }
}

class Account extends DepositOnlyAccount {
  withdraw(amount) {
    throw new Error("withdraw() must be implemented.");
  }
}

class SavingAccount extends Account {
  constructor() {
    super();
    this.balance = 0;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in the saving account, New Balance: ${this.balance}`);
  }

  withdraw(amount) {
    if (this.balance >= amount) {
      this.balance -= amount;
      console.log(`Withdrawn: ${amount} from the saving account. New Balance: ${this.balance}`);
    } else {
      console.log("Not enough balance in saving account");
    }
  }
}

class CurrentAccount extends Account {
  constructor() {
    super();
    this.balance = 0;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in the current account, New Balance: ${this.balance}`);
  }

  withdraw(amount) {
    if (this.balance >= amount) {
      this.balance -= amount;
      console.log(`Withdrawn: ${amount} from the current account. New Balance: ${this.balance}`);
    } else {
      console.log("Not enough balance in current account");
    }
  }
}

class FixedAccount extends DepositOnlyAccount {
  constructor() {
    super();
    this.balance = 0;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in the fixed account, New Balance: ${this.balance}`);
  }
}

class BankClient {
  constructor(depositAccounts, withdrawAccounts) {
    this.depositAccounts = depositAccounts;
    this.withdrawAccounts = withdrawAccounts;
  }

  processTransactions() {
    for (const acc of this.withdrawAccounts) {
      acc.deposit(100);
      acc.withdraw(40);
    }

    for (const acc of this.depositAccounts) {
      acc.deposit(500);
    }
  }
}

// Test
const withdrawAccounts = [
  new SavingAccount(),
  new CurrentAccount()
];

const depositAccounts = [
  new FixedAccount()
];

const client = new BankClient(depositAccounts, withdrawAccounts);
client.processTransactions();
