#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
// #include<boost/lexical_cast.hpp>

using namespace std;
// using namespace boost;
// struct Journal{
//     string title;
//     vector<string> entries;
//     Journal(const string &title): title(title){}
//     void add_entry(const string &entry)
//     {
//         static int count=1;

//     }

// };

//"A class should have only one reason to change."

// // example 1
// class Report
// {
// private:
//     vector<string> reports;
// public:
//     // addReport
//     void addReport(const string &report)
//     {
//         reports.push_back(report);
//     }
//     // printReport
//     void display() const
//     {
//         for (const auto &it : reports)
//         {
//             cout << it << "\n";
//         }
//     }
//     // saveReport
//     void saveToFile(const string &filename)
//     {
//         cout<<"saving reports to file: "<<filename<<"\n";
//     }
// };

// example 2
class ReportManager
{
private:
    vector<string> reports;

public:
    void addReport(const string &report)
    {
        reports.push_back(report);
    }
    vector<string> getReport() const
    {
        return reports;
    }
};

class PrintReport
{
private:
public:
    void display(vector<string> &vec)
    {
        for (const auto &it : vec)
        {
            cout << it << "\n";
        }
    }
};

class ReportSaver
{
public:
    void saveReportsToFile(const vector<string> &reports, const string &filename) const
    {
        ofstream file(filename);
        if (file.is_open())
        {
            for (const auto &report : reports)
            {
                file << report << endl;
            }
            file.close();
            cout << "Reports saved to " << filename << endl;
        }
        else
        {
            cerr << "Failed to open file: " << filename << endl;
        }
    }
};
int main()
{
    getchar();
    return 0;
}
