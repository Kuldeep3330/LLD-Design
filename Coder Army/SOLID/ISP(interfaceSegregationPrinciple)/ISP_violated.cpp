#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public Shape
{
private:
    double side;

public:
    Square(double side) : side(side) {}

    double area() override
    {
        return side * side;
    }

    double volume() override
    {
        throw logic_error("volume not applicable for square");
    }
};

class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double area() override
    {
        return length * width;
    }

    double volume() override
    {
        throw logic_error("volume not applicable for Rectangle");
    }
};

class Cube : public Shape
{
private:
    double side;

public:
    Cube(double side) : side(side) {}

    double area() override
    {
        return 6 * side * side;
    }

    double volume() override
    {
        return side * side * side;
    }
};

int main()
{
    Shape *square = new Square(5);
    Shape *rectangle = new Rectangle(3, 4);
    Shape *cube = new Cube(5);

    cout << " area of Square " << square->area() << endl;
    cout << " area of rectangle " << rectangle->area() << endl;
    cout << " area of cube " << cube->area() << endl;
    cout << " volume of cube " << cube->volume() << endl;
    cout << " volume of rectangle " << rectangle->volume() << endl;
    cout << " volume of Square " << square->volume() << endl;

    delete square;
    delete rectangle;
    delete cube;
    return 0;
}