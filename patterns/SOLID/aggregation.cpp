#include <bits/stdc++.h>
using namespace std;

// // Aggregation example 1
// class Student
// {
// private:
//     int id;
//     string name;
// public:
//     Student(int id, const string &name) : id(id), name(name) {}
//     void display() const
//     {
//         cout << "id: " << id << "name: " << name << endl;
//     }
// };
// class University
// {
// private:
//     vector<Student *> students; // Aggregation: University "has-a" Students
// public:
//     void addStudents(Student *stu)
//     {
//         students.push_back(stu);
//     }
//     void displayStu()
//     {
//         for (const auto &it : students)
//         {
//             it->display();
//         }
//     }
// };

// Aggregation example 2
// employee and company
class Employee
{
private:
    int id;
    string name;

public:
    Employee(const string &name, int id) : name(name), id(id) {}
    void display()
    {
        cout << "employee name: " << name << " id: " << id << endl;
    }
};
class Company
{
private:
    vector<Employee *> emps;

public:
    void addEmployee(Employee *emp)
    {
        emps.push_back(emp);
    }
    void showEmployee() const
    {
        for (auto &it : emps)
        {
            it->display();
        }
    }
};

int main()
{
    Employee emp1("kullu", 12), emp2("shibhu", 21);
    Company c1;
    c1.addEmployee(&emp1);
    c1.addEmployee(&emp2);
    c1.showEmployee();

    return 0;
}