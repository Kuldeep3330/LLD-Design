#include <iostream>
#include <string>
using namespace std;
class Handler
{
protected:
    Handler *nextHandler;

public:
    Handler() : nextHandler(nullptr) {}
    void setNextHandler(Handler *handler)
    {
        nextHandler = handler;
    }
    virtual void handleRequest(const string &request) = 0;
    virtual ~Handler() {}
};
// concrete handler
class TeamLead : public Handler
{
public:
    void handleRequest(const string &request) override
    {
        if (request == "Team Task")
        {
            cout << "Team Lead has handled the request" << request << endl;
        }
        else if (nextHandler)
        {
            nextHandler->handleRequest(request);
        }
        else
        {
            cout << "Request: " << request << " could not be handled." << endl;
        }
    }
};
class Manager : public Handler
{
public:
    void handleRequest(const string &request) override
    {
        if (request == "Budget approval")
        {
            cout << "Manager has handled the request" << request << endl;
        }
        else if (nextHandler)
        {
            nextHandler->handleRequest(request);
        }
        else
        {
            cout << "Request: " << request << " could not be handled." << endl;
        }
    }
};

class HR : public Handler
{
public:
    void handleRequest(const string &request) override
    {
        if (request == "Recruitment")
        {
            cout << "HR has handled the request" << request << endl;
        }
        else if (nextHandler)
        {
            nextHandler->handleRequest(request);
        }
        else
        {
            cout << "Request: " << request << " could not be handled." << endl;
        }
    }
};

int main()
{
    Handler *teamLead = new TeamLead();
    Handler *manager = new Manager();
    Handler *hr = new HR();
    teamLead->setNextHandler(manager);
    manager->setNextHandler(hr);
    // send request
    teamLead->handleRequest("Team Task");
    teamLead->handleRequest("Budget Approval");
    teamLead->handleRequest("Recruitment");
    teamLead->handleRequest("Unknown Request");
    delete teamLead;
    delete hr;
    delete manager;

    return 0;
}