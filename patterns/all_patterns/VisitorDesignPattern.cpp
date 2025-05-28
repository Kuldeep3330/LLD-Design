#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;
/*
Consider a tax calculation system. Different types of employees (e.g., permanent, contract) need different tax calculations. Instead of embedding the tax logic inside the employee classes, a tax calculator (visitor) can handle it.
*/

class PermanentEmployee;
class ContractEmployee;

class Visitor
{
public:
    virtual void visit(PermanentEmployee *employee) = 0;
    virtual void visit(ContractEmployee *employee) = 0;
    virtual ~Visitor() {}
};

// element interface(Defines an interface for accepting visitors)
class Employee
{
public:
    virtual void accept(Visitor *visitor) = 0;
    virtual ~Employee() {}
};
// concrete employees(Implements the accept method and provides data to the visitor.)
class PermanentEmployee : public Employee
{
private:
    string name;
    double salary;

public:
    PermanentEmployee(const string &name, double salary) : name(name), salary(salary) {}

    double getSalary() const { return salary; }
    string getName() const { return name; }

    void accept(Visitor *visitor) override
    {
        visitor->visit(this);
    }
};

class ContractEmployee : public Employee
{
private:
    string name;
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(const string &name, double hourlyRate, int hoursWorked)
        : name(name), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double getHourlyRate() const { return hourlyRate; }
    int getHoursWorked() const { return hoursWorked; }
    string getName() const { return name; }

    void accept(Visitor *visitor) override
    {
        visitor->visit(this);
    }
};

// concrete Visitors(implements specific operation for each element type)

class TaxCalculator : public Visitor
{
public:
    void visit(PermanentEmployee *employee) override
    {
        double tax = employee->getSalary() * 0.2; // 20% tax for permanent employees
        cout << "Permanent Employee: " << employee->getName()
             << ", Tax: $" << tax << endl;
    }

    void visit(ContractEmployee *employee) override
    {
        double income = employee->getHourlyRate() * employee->getHoursWorked();
        double tax = income * 0.1; // 10% tax for contract employees
        cout << "Contract Employee: " << employee->getName()
             << ", Tax: $" << tax << endl;
    }
};

int main()
{
    vector<unique_ptr<Employee>> employees;

    employees.push_back(make_unique<PermanentEmployee>("Alice", 50000));
    employees.push_back(make_unique<ContractEmployee>("Bob", 50, 100));

    TaxCalculator taxCalculator;

    for (const auto &employee : employees)
    {
        employee->accept(&taxCalculator);
    }

    return 0;
}
 