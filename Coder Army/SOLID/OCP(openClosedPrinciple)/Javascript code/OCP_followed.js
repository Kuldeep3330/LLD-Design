class Product{
  constructor(id, name, price){
    this.id=id
    this.name=name
    this.price=price
  }
}

class ShoppingCart{
  constructor(){
    this.products=[]
  }

  addToCart(product){
    this.products.push(product)
  }

  removeProduct(id){
    const originalLength=this.products.length
    this.products= this.products.filter(p=>p.id!==id)
    if (this.products.length < originalLength) {
      console.log(`Product with ID ${id} has been removed successfully`)
    } else {
      console.log(`Product with ID ${id} has not been found`)
    }
  }

  getAllProducts(){
    return this.products
  }

  totalPrice(){
    let total= this.products.reduce((sum, product)=>sum+product.price, 0)
    return total
  }
}

class Invoice{
  constructor(cart){
    this.cart=cart
  }

  printInvoice(){
    console.log(`Your Invoice...`);
    this.cart.getAllProducts().forEach(p => {
      console.log(`${p.name} - ₹${p.price}`)
    })
    console.log(`Total: ₹${this.cart.totalPrice()}`)    
  }
}


class Database{
  saveToDB(cart){

  }
}

class SaveToFile extends Database{
  saveToDB(cart){
    console.log("save to file")
  }
}
class SaveToMongoDB extends Database{
  saveToDB(cart){
    console.log("save to MongoDB")
  }
}
class SaveToMySql extends Database{
  saveToDB(cart){
    console.log("save to MySql")
  }
}

//client
const p1 = new Product(1, "Apple", 220)
const p2 = new Product(2, "Orange", 60)
const p3 = new Product(3, "Pineapple", 100)

const cart= new ShoppingCart()
cart.addToCart(p1)
cart.addToCart(p2)
cart.addToCart(p3)

const invoice = new Invoice(cart)
invoice.printInvoice()

let db = new SaveToFile()
db.saveToDB(cart)

db = new SaveToMongoDB()
db.saveToDB(cart)