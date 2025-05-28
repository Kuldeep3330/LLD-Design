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
// more examples on factory design pattern
// 2.logger factory
class Logger
{
public:
    virtual void log(const string &message) const = 0;
    virtual ~Logger() = default;
};
// concrete prodects
class ConsoleLogger : public Logger
{
public:
    void log(const string &message) const override
    {
        cout << "Console Logger: " << message << endl;
    }
};
class FileLogger : public Logger
{
public:
    void log(const string &message) const override
    {
        cout << "File Logger: Writing '" << message << "' to a file." << endl;
    }
};
// Factory class
class LoggerFactory
{
public:
    static Logger *createLogger(const string &type)
    {
        if (type == "console")
            return new ConsoleLogger();
        else if (type == "file")
            return new FileLogger();
        else
            return nullptr;
    }
};

// 3.operating system factory
// product interface
class OperatingSystem
{
public:
    virtual void boot() const = 0;
    virtual ~OperatingSystem() = default;
};
class Window : public OperatingSystem
{
public:
    void boot() const override
    {
        cout << "Booting Window OS" << endl;
    }
};
class Linux : public OperatingSystem
{
public:
    void boot() const override
    {
        cout << "Booting Linux OS" << endl;
    }
};
// Factory class
class OSFactory
{
public:
    static OperatingSystem *createOS(const string &osType)
    {
        if (osType == "Window")
        {
            return new Window();
        }
        else if (osType == "Linux")
        {
            return new Linux();
        }
        else
        {
            return nullptr;
        }
    }
};
int main()
{
    // Operating system
    OperatingSystem *os = OSFactory::createOS("Window");
    if (os)
    {
        os->boot();
        delete os;
    }

    os = OSFactory::createOS("Linux");
    if (os)
    {
        os->boot();
        delete os;
    }

    // Logger factory
    // Logger *logger = LoggerFactory::createLogger("console");
    // if (logger)
    // {
    //     logger->log("test message 1");
    //     delete logger;
    // }
    // logger = LoggerFactory::createLogger("file");
    // if (logger)
    // {
    //     logger->log("test message 2");
    //     delete logger;
    // }

    // abstract factory
    // AbstractFactory *factory = new CircleFactory();
    // Shape *shape = factory->createShape();
    // Color *color = factory->createColor();
    // shape->draw();
    // color->fill();

    // delete color;
    // delete shape;
    // delete factory;
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