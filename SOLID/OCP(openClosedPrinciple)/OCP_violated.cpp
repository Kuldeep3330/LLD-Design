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

class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addToCart(Product *p)
    {
        products.push_back(p);
    }

    void removeProduct(int id)
    {
        auto it = remove_if(products.begin(), products.end(), [id](Product *p)
                            { return p->id == id; });
        if (it != products.end())
        {
            products.erase(it, products.end());
            cout << "Product with ID" << id << " has been removed successfully\n";
        }
        else
        {
            cout << "Product with ID" << id << " has not been found\n";
        }
    }

    const vector<Product *> getAllProducts() const
    {
        return products;
    }

    double toatalPrice()
    {
        double total = 0;
        for (auto &p : products)
        {
            total += p->price;
        }
        return total;
    }
};

// for printing the invoice
class Invoice
{
private:
    ShoppingCart *sc;

public:
    Invoice(ShoppingCart *sc) : sc(sc) {}

    void printInvoice()
    {
        cout << "You bill for the cart is\n";
        for (auto *p : sc->getAllProducts())
        {
            cout << p->name << " - rs" << p->price << endl;
        }
        cout << "Total: rs" << sc->toatalPrice() << endl;
    }
};

// database OCP violates
class Database
{
private:
    ShoppingCart *sc;

public:
    Database(ShoppingCart *sc) : sc(sc) {}

    // save to file
    void saveToFile()
    {
        cout << "You shopping cart purchase has been saved to the file\n";
    }
    // save to mysql
    void saveToMySQL()
    {
        cout << "You shopping cart purchase has been saved to the MySql db\n";
    }
    // save to mongodb
    void saveToMongoDb()
    {
        cout << "You shopping cart purchase has been saved to the Mongodb\n";
    }
};

int main()
{
    Product *p1 = new Product(1, "Apple", 220);
    Product *p2 = new Product(2, "Orange", 60);
    Product *p3 = new Product(3, "Pineapple", 100);

    ShoppingCart *sc = new ShoppingCart();
    sc->addToCart(p1);
    sc->addToCart(p2);
    sc->addToCart(p3);

    Invoice *printer = new Invoice(sc);
    printer->printInvoice();

    Database *db = new Database(sc);
    db->saveToFile();
    db->saveToMongoDb();
    db->saveToMySQL();

    delete p1;
    delete p2;
    delete p3;
    delete sc;
    delete printer;
    delete db;
    return 0;
}