class Account{
  deposit(amount){}
  withdraw(amount){}
}

class SavingAccount extends Account{
  constructor(){
    super()
    this.balance=0
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

class CurrentAccount extends Account{
  constructor(){
    super()
    this.balance=0
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

class FixedAccount extends Account{
  constructor(){
    super()
    this.balance=0
  }
  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in the fixed account, New Balance: ${this.balance}`);
  }

  withdraw(amount) {
    throw new Error("Withdrawal is not allowed!");
  }
}

class BankClient{
  constructor(accounts){
    this.accounts=accounts
  }

  processTransaction(){
    for(const acc of this.accounts){
      acc.deposit(100);
      try {
        acc.withdraw(40)
      } catch (error) {
        console.log(`Exception: ${error.message}`);
        
      }
    }
  }
}

const accounts=[
  new SavingAccount(),
  new CurrentAccount(),
  new FixedAccount
]

const client = new BankClient(accounts)
client.processTransaction()