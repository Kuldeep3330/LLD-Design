#include <bits/stdc++.h>
using namespace std;

// Product
class Product
{
public:
    int id;
    string name;
    double price;
    Product(int id, string name, double price) : id(id), name(name), price(price) {}
};

// Shopping cart
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addToCart(Product *p)
    {
        products.push_back(p);
    }
    const vector<Product *> &getAllProducts() const
    {
        return products;
    }
    void removeProduct(int id)
    {
        auto it = remove_if(products.begin(), products.end(), [id](Product *p)
                            { return p->id == id; });

        if (it != products.end())
        {
            products.erase(it, products.end());
            cout << "Product with given id removed\n";
        }
        else
        {
            cout << "Product with given id not found\n";
        }
    }
    double calculateTotal()
    {
        double total = 0;
        for (auto &p : products)
        {
            total += p->price;
        }
        return total;
    }
};

// Invoice class for printing slip
class Invoice
{
private:
    ShoppingCart *sc;

public:
    Invoice(ShoppingCart *sc) : sc(sc) {}

    void printToInvoice()
    {
        cout << "Your invoice is here\n";
        for (auto &p : sc->getAllProducts())
        {
            cout << p->name << " - rs" << p->price << endl;
        }
        cout << "Your Total:- rs" << sc->calculateTotal() << endl;
    }
};

// abstract
class Database
{
private:
    ShoppingCart *cart;

public:
    virtual void saveToDb(ShoppingCart *sc) = 0;
    virtual ~Database() {}
};
class SaveTofile : public Database
{
public:
    void saveToDb(ShoppingCart *sc) override
    {
        cout << "save to file\n";
    }
};
class SaveToMongoDB : public Database
{
public:
    void saveToDb(ShoppingCart *sc) override
    {
        cout << "save to MongoDB\n";
    }
};

int main()
{
    Product *p1 = new Product(1, "Apple", 200);
    Product *p2 = new Product(2, "Orange", 40);
    Product *p3 = new Product(3, "Banana", 80);

    ShoppingCart *sc = new ShoppingCart();
    sc->addToCart(p1);
    sc->addToCart(p2);
    sc->addToCart(p3);

    Invoice *printer = new Invoice(sc);
    printer->printToInvoice();

    Database *db = new SaveTofile();
    db->saveToDb(sc);

    db = new SaveToMongoDB();
    db->saveToDb(sc);

    delete p1;
    delete p2;
    delete p3;
    delete sc;
    delete printer;
    delete db;

    return 0;
}