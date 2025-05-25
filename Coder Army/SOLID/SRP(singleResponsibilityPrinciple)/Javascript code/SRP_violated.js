class Product {
  constructor(name, price, id) {
    this.name = name
    this.price = price
    this.id = id //minor bug fixed this.id = this.id
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
    const originalLength = this.products.length;
    this.products = this.products.filter(product => product.id !== id);
    if (this.products.length < originalLength) {
        console.log(`Product with ID ${id} has been removed`);
    } else {
        console.log(`Product with ID ${id} not found`);
    }
}


  getProducts() {
    return this.products
  }
  calculateTotal() {
    return this.products.reduce((sum, product) => (sum += product.price), 0)
  }

  saveToDB() {
    console.log('Your cart has been saved to the DB')
  }

  printInvoice() {
    console.log('your Invoice: ')
    this.products.forEach((product) => {
      console.log(`${product.name} - rs${product.price}`)
    })
    console.log(`Total: rs${this.calculateTotal()}`)
  }
}

const cart = new ShoppingCart()

const p1 = new Product('Apple', 200, 1)
const p2 = new Product('Milk', 70, 2)
const p3 = new Product('Pineapple', 120, 3)

cart.addProduct(p1)
cart.addProduct(p2)
cart.addProduct(p3)

cart.calculateTotal()
cart.printInvoice()
cart.saveToDB()

cart.removeProduct(3)
