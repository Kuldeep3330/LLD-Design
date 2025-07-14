class Parent {
  print(msg) {
    console.log("Parent:", msg);
  }
}

class Child extends Parent {
  print(msg) {
    console.log("Child:", msg);
  }
}

class Client {
  constructor(p) {
    this.p = p;
  }

  printMsg() {
    this.p.print("Hello");
  }
}

// You can create instances
const parent = new Parent();
const child = new Child();

// Use Parent
// const client = new Client(parent);

// Use Child
const client = new Client(child);

client.printMsg();
