#include <iostream>
using namespace std;

class TwoDShape
{
public:
    virtual double area() = 0;
};

class ThreeDShape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public TwoDShape
{
private:
    double side;

public:
    Square(double side) : side(side) {}

    double area() override
    {
        return side * side;
    }
};

class Rectangle : public TwoDShape
{
private:
    double length, width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}

    double area() override
    {
        return length * width;
    }
};

class Cube : public ThreeDShape
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
    TwoDShape *square = new Square(5);
    TwoDShape *rectangle = new Rectangle(3, 4);
    ThreeDShape *cube = new Cube(5);

    cout << " area of Square " << square->area() << endl;
    cout << " area of rectangle " << rectangle->area() << endl;
    cout << " area of cube " << cube->area() << endl;
    cout << " volume of cube " << cube->volume() << endl;

    delete square;
    delete rectangle;
    delete cube;
    return 0;
}