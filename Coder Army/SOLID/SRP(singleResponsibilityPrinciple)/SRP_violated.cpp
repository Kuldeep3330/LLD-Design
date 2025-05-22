#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
    string name;
    double price;
    int id;

    Product(string name, double price, int id) : name(name), price(price), id(id) {}
};

class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProduct(Product *p)
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
            cout << "Product with ID " << id << " has been removed\n";
        }
        else
        {
            cout << "Product with ID " << id << " not found\n";
        }
    }

    vector<Product *> getProducts()
    {
        return products;
    }

    double calculateTotal()
    {
        double total = 0;
        for (auto prod : products)
        {
            total += prod->price;
        }
        return total;
    }

    void saveToDB()
    {
        cout << "you cart has been saved to db\n";
    }

    void printInvoice()
    {
        cout << "Your shopping cart bill\n";
        for (auto &prod : products)
        {
            cout << prod->name << " - rs" << prod->price << endl;
        }
        cout << "Total: rs" << calculateTotal() << endl;
    }
};

int main()
{
    ShoppingCart *cart = new ShoppingCart();
    Product *p1 = new Product("Apple", 200, 1);
    Product *p2 = new Product("Namkeen", 120, 2);
    Product *p3 = new Product("Milk", 70, 3);
    cart->addProduct(p1);
    cart->addProduct(p2);
    cart->addProduct(p3);
    cart->getProducts();
    cart->printInvoice();
    cart->saveToDB();

    cart->removeProduct(2);
    cart->getProducts();
    return 0;
}