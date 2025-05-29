class Shape{
  area(){}
  volume(){}
}

class Square extends Shape{
  constructor(side){
    super();
    this.side=side
  }

  area(){
    return this.side*this.side;
  }
  volume(){
    throw new Error("we don't volume for 2-D shapes")
  }

}
class RectAngle extends Shape{
  constructor(length, breadth){
    super()
    this.length=length,
    this.breadth=breadth
  }

  area(){
    return this.length * this.breadth;
  }
  volume(){
    throw new Error("we don't volume for 2-D shapes")
  }
}

class Cube extends Shape{
  constructor(side){
    super()
    this.side=side
  }

  area(){
    return 6*this.side*this.side;
  }
  volume(){
    return this.side*this.side*this.side
  }
}

const square= new Square(4);
const rectangle= new RectAngle(9, 8)
const cube= new Cube(5);

console.log("Square Area:", square.area());
try {
  console.log("Square Volume:", square.volume());
} catch (e) {
  console.error("Square Volume Error:", e.message);
}

console.log("Rectangle Area:", rectangle.area());
try {
  console.log("Rectangle Volume:", rectangle.volume());
} catch (e) {
  console.error("Rectangle Volume Error:", e.message);
}

console.log("Cube Area:", cube.area());
console.log("Cube Volume:", cube.volume());

