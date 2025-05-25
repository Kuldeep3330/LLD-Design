class Product {
  constructor(id, name, price) {
    this.id = id
    this.name = name
    this.price = price
  }
}

class ShoppingCart {
  constructor() {
    this.products = []
  }

  addProduct(product) {
    this.products.push(product)
  }

  removeProduct(id) {
    const originalLength = this.products.length
    this.products = this.products.filter((product) => product.id !== id)
    if (this.products.length < originalLength) {
      console.log(`Product with ID ${id} has been removed`)
    } else {
      console.log(`Product with ID ${id} not found`)
    }
  }

  getProducts() {
    return this.products
  }

  calculateTotal() {
    return this.products.reduce((sum, product) => sum + product.price, 0)
  }
}

class Invoice {
  constructor(cart) {
    this.cart = cart
  }

  printInvoice() {
    console.log(`Your Invoice:`)
    this.cart.getProducts().forEach((product) => {
      console.log(`${product.name} - ₹${product.price}`)  // Fixed typo: p.price → product.price
    })
    console.log(`Your cart total: ₹${this.cart.calculateTotal()}`)
  }
}

class Database {
  constructor(cart) {
    this.cart = cart
  }

  saveToDB() {
    console.log("Your shopping cart has been saved to the database.")
  }
}

// Usage
const p1 = new Product(1, "Apple", 100)
const p2 = new Product(2, "Milk", 60)
const p3 = new Product(3, "Bread", 40)

const cart = new ShoppingCart()
cart.addProduct(p1)
cart.addProduct(p2)
cart.addProduct(p3)

const invoicePrinter = new Invoice(cart)
invoicePrinter.printInvoice()

const db = new Database(cart)
db.saveToDB()
