#include <iostream>
using namespace std;
// simple factory
// A shape-drawing appliaction needs to create different shapes like circle and rectangle
// class Shape
// {
// public:
//     virtual void draw() const = 0;
//     virtual ~Shape() = default;
// };
// // concrete products
// class Circle : public Shape
// {
// public:
//     void draw() const override
//     {
//         cout << "drawing a circle\n";
//     }
// };
// class Rectangle : public Shape
// {
// public:
//     void draw() const override
//     {
//         cout << "drawing a Rectangle\n";
//     }
// };
// // factory class
// class ShapeFactory
// {
// public:
//     static Shape *createShape(const string &type)
//     {
//         if (type == "Circle")
//         {
//             return new Circle();
//         }
//         else if (type == "Rectangle")
//         {
//             return new Rectangle();
//         }
//         else
//         {
//             return nullptr;
//         }
//     }
// };

// factory method
// class Shape
// {
// public:
//     virtual void draw() const = 0;
//     virtual ~Shape() = default;
// };
// // concrete Products
// class Circle : public Shape
// {
// public:
//     void draw() const override
//     {
//         cout << "Drawing a Circle" << endl;
//     }
// };
// class Rectangle : public Shape
// {
// public:
//     void draw() const override
//     {
//         cout << "Drawing a Rectangle" << endl;
//     }
// };
// // Factory interface
// class ShapeFactory
// {
// public:
//     virtual Shape *createShape() const = 0; // factory method
//     virtual ~ShapeFactory() = default;
// };
// // concrete Fcatories
// class CircleFactory : public ShapeFactory
// {
// public:
//     Shape *createShape() const override
//     {
//         return new Circle();
//     }
// };

// class RectangleFactory : public ShapeFactory
// {
// public:
//     Shape *createShape() const override
//     {
//         return new Rectangle();
//     }
// };

// Abstract Factory
// Product interface
class Shape
{
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};
class Color
{
public:
    virtual void fill() const = 0;
    virtual ~Color() = default;
};
// concrete products
class Circle : public Shape
{
public:
    void draw() const override
    {
        cout << "drawing Circle\n";
    }
};
class Rectangle : public Shape
{
public:
    void draw() const override
    {
        cout << "drawing Rectangle\n";
    }
};
class Red : public Color
{
public:
    void fill() const override
    {
        cout << "filling with Red color\n";
    }
};
class Blue : public Color
{
public:
    void fill() const override
    {
        cout << "filling with Blue color\n";
    }
};
// Abstract factory
class AbstractFactory
{
public:
    virtual Shape *createShape() const = 0;
    virtual Color *createColor() const = 0;
    virtual ~AbstractFactory() = default;
};
// concrete factories
class CircleFactory : public AbstractFactory
{
public:
    Shape *createShape() const override
    {
        return new Circle();
    }
    Color *createColor() const override
    {
        return new Red();
    }
};
class RectangleFactory : public AbstractFactory
{
public:
    Shape *createShape() const override
    {
        return new Rectangle();
    }
    Color *createColor() const override
    {
        return new Blue();
    }
};
int main()
{

    // abstract factory
    AbstractFactory *factory = new CircleFactory();
    Shape *shape = factory->createShape();
    Color *color = factory->createColor();
    shape->draw();
    color->fill();

    delete color;
    delete shape;
    delete factory;
    // factory method
    // ShapeFactory *circleFactory = new CircleFactory();
    // ShapeFactory *rectangleFactory = new RectangleFactory();
    // Shape *shape1 = circleFactory->createShape();
    // Shape *shape2 = rectangleFactory->createShape();
    // shape1->draw();
    // shape2->draw();

    // delete shape1;
    // delete shape2;
    // delete circleFactory;
    // delete rectangleFactory;

    // //simple factory
    // Shape *shape1 = ShapeFactory::createShape("Circle");
    // Shape *shape2 = ShapeFactory::createShape("Rectangle");

    // if (shape1)
    // {
    //     shape1->draw();
    //     delete shape1;
    // }

    // if (shape2)
    // {
    //     shape2->draw();
    //     delete shape2;
    // }
    return 0;
}