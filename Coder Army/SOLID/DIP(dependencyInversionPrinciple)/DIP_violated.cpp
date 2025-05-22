#include <iostream>
using namespace std;

class MySql
{
public:
    void saveToSql(string data)
    {
        cout << "Insert into users value ('" << data << "')" << endl;
    }
};

class Mongodb
{
public:
    void saveToMongodb(string data)
    {
        cout << "Insert into db.company.users value ('" << data << "')" << endl;
    }
};

class UserService
{
private:
    MySql sqlDB;
    Mongodb mongoDB;

public:
    void storeUserToSQL(string user)
    {
        sqlDB.saveToSql(user);
    }
    void storeUserToMongoDB(string user)
    {
        mongoDB.saveToMongodb(user);
    }
};

int main()
{
    UserService service;
    service.storeUserToMongoDB("Kuldeep");
    service.storeUserToSQL("Kumar");

    return 0;
}