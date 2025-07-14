class Animal {
  // Common animal logic
}

class Dog extends Animal {
  // Dog-specific logic
}

class Parent {
  getAnimal() {
    console.log("Parent : Returning Animal instance");
    return new Animal();
  }
}

class Child extends Parent {
  getAnimal() {
    console.log("Child : Returning Dog instance");
    return new Dog();
  }
}

class Client {
  constructor(p) {
    this.p = p;
  }

  takeAnimal() {
    this.p.getAnimal();
  }
}

// Create Parent and Child instances
const parent = new Parent();
const child = new Child();

// Use Child
const client = new Client(child);
// Or use Parent
// const client = new Client(parent);

client.takeAnimal();
