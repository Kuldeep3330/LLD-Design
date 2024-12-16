#include <bits/stdc++.h>
using namespace std;
// Objects of a superclass should be replaceable with objects of its subclasses
// without altering the correctness of the program.
// example
class Rectangle
{
private:
    int height, width;

public:
    // setter
    virtual void setHeight(int h)
    {
        height = h;
    }
    virtual void setWidth(int w)
    {
        width = w;
    }
    // getter
    int getWidth() { return width; }
    int getHeight() { return height; }
    // area
    virtual int getArea() const { return width * height; }
};

class Square : public Rectangle
{
public:
    void setHeight(int h) override
    {
        Rectangle::setHeight(h);
        Rectangle::setWidth(h);
    }
    void setWidth(int w) override
    {
        Rectangle::setHeight(w);
        Rectangle::setWidth(w);
    }
    void printArea(Rectangle &rect)
    {
        rect.setWidth(5);
        rect.setHeight(10);
        cout << "Area: " << rect.getArea();
    }
};

int main()
{
    Rectangle rect;
    Square sq;

    sq.printArea(rect); // Output: Area: 50
    sq.printArea(sq);   // Area: 100
    return 0;
}