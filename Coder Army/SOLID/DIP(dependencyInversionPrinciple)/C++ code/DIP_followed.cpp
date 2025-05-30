#include <bits/stdc++.h>
using namespace std;

class Database
{
public:
    virtual void save(string data) = 0;
};

class MySQLDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Insert into db.company.users value ('" << data << "')" << endl;
    }
};
class MongodbDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Insert into MongodbDatabase value ('" << data << "')" << endl;
    }
};

class CassandraDatabase : public Database
{
public:
    void save(string data) override
    {
        cout << "Insert into CassandraDatabase value ('" << data << "')" << endl;
    }
};

class UserServices
{
private:
    Database *db; // dependency injection

public:
    UserServices(Database *db) : db(db) {}

    void storeToDB(string user)
    {
        db->save(user);
    }
};
int main()
{

    MySQLDatabase mySQL;
    MongodbDatabase mongodb;
    CassandraDatabase cdb;

    UserServices service(&mySQL);
    service.storeToDB("Kuldeep");

    return 0;
}