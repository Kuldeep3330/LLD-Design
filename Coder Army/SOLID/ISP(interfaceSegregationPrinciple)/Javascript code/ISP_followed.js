class TwoDShape{
  area(){}
}

class ThreeDShape{
  area(){}
  volume(){}
}

class Square extends TwoDShape{
  constructor(side){
    super()
    this.side=side
  }
  area(){
    return this.side*this.side
  }
}

class Rectangle extends TwoDShape{
  constructor(length, breadth){
    super()
    this.length=length
    this.breadth= breadth
  }
  area(){
    return this.length*this.breadth
  }
}

class Cube extends ThreeDShape{
  constructor(side){
    super()
    this.side=side
  }
  area(){
    return 6* this.side*this.side
  }
  volume(){
    return this.side*this.side*this.side
  }
}

const square= new Square(4);
const rectangle= new Rectangle(9, 8)
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

