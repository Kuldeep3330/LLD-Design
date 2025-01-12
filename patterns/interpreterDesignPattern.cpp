#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
using namespace std;

class Expression
{
public:
    virtual int interpret(const unordered_map<string, int> &context) const = 0;
    virtual ~Expression() {}
};
class Number : public Expression
{
private:
    int value;

public:
    Number(int value) : value(value) {}
    int interpret(const unordered_map<string, int> &context) const override
    {
        return value;
    }
};
class Variable : public Expression
{
private:
    string name;

public:
    Variable(const string &name) : name(name) {}
    int interpret(const unordered_map<string, int> &context) const override
    {
        return context.at(name); //
    }
};
// non terminal expression
class Add : public Expression
{
private:
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;

public:
    Add(unique_ptr<Expression> leftExpr, unique_ptr<Expression> rightExpr)
        : left(move(leftExpr)), right(move(rightExpr)) {}
    int interpret(const unordered_map<string, int> &context) const override
    {
        return left->interpret(context) + right->interpret(context);
    }
};
class Subtract : public Expression
{
private:
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;

public:
    Subtract(unique_ptr<Expression> leftExpr, unique_ptr<Expression> rightExpr)
        : left(move(leftExpr)), right(move(rightExpr)) {}
    int interpret(const unordered_map<string, int> &context) const override
    {
        return left->interpret(context) - right->interpret(context);
    }
};
class AndExpression : public Expression
{
private:
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;

public:
    AndExpression(unique_ptr<Expression> leftExpr, unique_ptr<Expression> rightExpr)
        : left(move(leftExpr)), right(move(rightExpr)) {}

    int interpret(const unordered_map<string, int> &context) const override
    {
        return left->interpret(context) && right->interpret(context);
    }
};

class OrExpression : public Expression
{
private:
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;

public:
    OrExpression(unique_ptr<Expression> leftExpr, unique_ptr<Expression> rightExpr)
        : left(move(leftExpr)), right(move(rightExpr)) {}

    int interpret(const unordered_map<string, int> &context) const override
    {
        return left->interpret(context) || right->interpret(context);
    }
};

int main()
{

    unordered_map<string, int> context = {{"x", 1}, {"y", 0}, {"z", 1}};

    // Build the expression: (x AND y) OR z
    unique_ptr<Expression> expression = make_unique<OrExpression>(
        make_unique<AndExpression>(
            make_unique<Variable>("x"),
            make_unique<Variable>("y")),
        make_unique<Variable>("z"));

    // Interpret the expression
    cout << "Result: " << expression->interpret(context) << endl;

    // // Context for variable values
    // unordered_map<string, int> context = {{"x", 5}, {"y", 3}};

    // // Build the expression: x + y - 2
    // unique_ptr<Expression> expression = make_unique<Subtract>(
    //     make_unique<Add>(
    //         make_unique<Variable>("x"), // x
    //         make_unique<Variable>("y")  // y
    //         ),
    //     make_unique<Number>(2) // - 2
    // );

    // // Interpret the expression
    // cout << "Result: " << expression->interpret(context) << endl;
    return 0;
}