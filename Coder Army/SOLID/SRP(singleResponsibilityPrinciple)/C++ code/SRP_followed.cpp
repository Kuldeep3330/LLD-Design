#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    int id;
    string name;
    double price;

    Product(int id, string name, double price) : id(id), name(name), price(price) {}
};

// shopping cart
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addToCart(Product *prod)
    {
        products.push_back(prod);
    }

    void removeProduct(int id)
    {
        auto it = remove_if(products.begin(), products.end(), [id](Product *p)
                            { return p->id == id; });

        if (it != products.end())
        {
            products.erase(it, products.end());
            cout << "Product with ID " << id << " has been removed\n";
        }
        else
        {
            cout << "Product with ID " << id << " not found\n";
        }
    }

    const vector<Product *> &getProducts() const
    {
        return products;
    }

    double calculatePrice()
    {
        double total = 0;
        for (auto &prod : products)
        {
            total += prod->price;
        }
        return total;
    }
};

class Invoice
{
private:
    ShoppingCart *sc;

public:
    Invoice(ShoppingCart *sc) : sc(sc) {}

    void printInvoice()
    {
        cout << "you cart invoice\n";
        for (auto p : sc->getProducts())
        {
            cout << p->name << " - rs" << p->price << endl;
        }
        cout << "you cart total: rs" << sc->calculatePrice() << endl;
    }
};

class Database
{
private:
    ShoppingCart *sc;

public:
    Database(ShoppingCart *sc) : sc(sc) {}

    void saveToDB()
    {
        cout << "you shopping cart has been saved to db\n";
    }
};

main()
{

    // Avoid raw new/delete for small programs
    Product *p1 = new Product(1, "Apple", 100);
    Product *p2 = new Product(2, "Milk", 60);
    Product *p3 = new Product(3, "Bread", 40);

    ShoppingCart *cart = new ShoppingCart();
    cart->addToCart(p1);
    cart->addToCart(p2);
    cart->addToCart(p3);

    Invoice *printer = new Invoice(cart);
    printer->printInvoice();

    Database *db = new Database(cart);
    db->saveToDB();

    // ShoppingCart cart;
    // cart.addToCart(p1);
    // cart.addToCart(p2);
    // cart.addToCart(p3);

    // Invoice invoice(&cart);
    // invoice.printInvoice();

    // Database db(&cart);
    // db.saveToDB();

    // cart.removeProduct(2);
    // invoice.printInvoice();

    delete p1;
    delete p2;
    delete p3;
    delete cart;
    delete printer;

    return 0;
}