// A Postcondition must be statisfied after a method is executed.
// Sub classes can strengthen the Postcondition but cannot weaken it.

/*The base class contract promises certain outcomes. A subclass 
should deliver at least that — or even more guarantees — 
so it doesn’t break the expectations of code using the base class. */

class Car {
  constructor() {
    this.speed = 0;
  }

  accelerate() {
    console.log("Accelerating");
    this.speed += 20;
  }

  brake() {
    console.log("Applying brakes");
    this.speed -= 20;
  }
}

class HybridCar extends Car {
  constructor() {
    super();
    this.charge = 0;
  }

  brake() {
    console.log("Applying brakes");
    this.speed -= 20;
    this.charge += 10;
  }
}

const hybridCar = new HybridCar();
hybridCar.brake(); // Works fine: speed reduces, charge increases
