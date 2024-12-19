// high level modules should not depend on low level module. both should depend on abstractions
#include <bits/stdc++.h>
using namespace std;

// interface
class Logger
{
public:
    virtual void log(const string &msg) = 0;
};

// low level module
class FileLogger : public Logger
{
public:
    void log(const string &msg)
    {
        cout << "logging to file " << msg << endl;
    }
};

// high level module
class Application
{
private:
    shared_ptr<Logger> logger;

public:
    Application(shared_ptr<Logger> logger) : logger(logger) {}

    void run()
    {
        logger->log("Application is running.");
    }
};

int main()
{
    shared_ptr<Logger> logger = make_shared<FileLogger>();
    Application app(logger);
    app.run();
    return 0;
}