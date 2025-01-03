#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// The observer DP is a behavioral design pattern where an object, known as the subject
// maintains a list of its dependent, called observers, and notifies them of any state changes
// when changes in one object require updates to multiple dependent objects
// for event driven systems or when implementing publish- subscribe mechanism
// we have 1.subject, 2.Observer, 3.Concrete Subject, 4.Concrete Observer
// Weather station
// class Observer
// {
// public:
//     virtual void update(float temperature, float humidity, float pressure) = 0;
//     virtual ~Observer() = default;
// };
// // Define the subject interface
// class Subject
// {
// public:
//     virtual void attach(Observer *observer) = 0;
//     virtual void detach(Observer *observer) = 0;
//     virtual void notify() = 0;
//     virtual ~Subject() = default;
// };
// // implement the concrete subject
// class WeatherData : public Subject
// {
// private:
//     vector<Observer *> observers;
//     float temperature, humidity, pressure;
// public:
//     void attach(Observer *observer) override
//     {
//         observers.push_back(observer);
//     }
//     void detach(Observer *observer) override
//     {
//         observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
//     }
//     void notify() override
//     {
//         for (auto it : observers)
//         {
//             it->update(temperature, humidity, pressure);
//         }
//     }
//     void setMeasurements(float temp, float humi, float press)
//     {
//         temperature = temp;
//         humidity = humi;
//         pressure = press;
//         notify();
//     }
// };
// // implement concrete observers
// class CurrentConditionDisplay : public Observer
// {
// public:
//     void update(float temperature, float humidity, float pressure) override
//     {
//         cout << temperature << " " << humidity << " " << pressure << endl;
//     }
// };
// class StatisticsDisplay : public Observer
// {
// private:
//     vector<float> temperatures;
// public:
//     void update(float temperature, float humidity, float pressure) override
//     {
//         temperatures.push_back(temperature);
//         float sum;
//         for (int i = 0; i < temperatures.size(); i++)
//         {
//             sum += temperatures[i];
//         }
//         float avgTemp = sum / temperatures.size();
//         cout << "Avg temperature: " << avgTemp << "°C\n";
//     }
// };

// stock price notification
// observer interface
// class StockObserver
// {
// public:
//     virtual void update(const string &stockName, float price) = 0;
//     virtual ~StockObserver() = default;
// };
// // subject Interface
// class Stock
// {
// public:
//     virtual void attach(StockObserver *observer) = 0;
//     virtual void detach(StockObserver *observer) = 0;
//     virtual void notify() = 0;
//     virtual ~Stock() = default;
// };
// // concrete Subject
// class StockMarket : public Stock
// {
// private:
//     vector<StockObserver *> observers;
//     string stockName;
//     float stockPrice;
// public:
//     void attach(StockObserver *observer) override
//     {
//         observers.push_back(observer);
//     }
//     void detach(StockObserver *observer) override
//     {
//         observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
//     }
//     void notify() override
//     {
//         for (auto it : observers)
//         {
//             it->update(stockName, stockPrice);
//         }
//     }
//     void setStockPrice(const string &name, float price)
//     {
//         stockName = name;
//         stockPrice = price;
//         notify();
//     }
// };
// // concrete observers
// class Investor : public StockObserver
// {
// private:
//     string name;
// public:
//     Investor(const string &name) : name(name) {}
//     void update(const string &stockName, float price) override
//     {
//         cout << "Investor: " << name << " notified: stock " << stockName << " is now rs" << price << endl;
//     }
// };

// News Agency System
// observer
// class NewsChannel
// {
// public:
//     virtual void update(const string &news) = 0;
//     virtual ~NewsChannel() = default;
// };
// // subject interface
// class NewsAgency
// {
// public:
//     virtual void addChannel(NewsChannel *channel) = 0;
//     virtual void removeChannel(NewsChannel *channel) = 0;
//     virtual void broadcast(const string &news) = 0;
//     virtual ~NewsAgency() = default;
// };
// // concrete subject
// class Agency : public NewsAgency
// {
// private:
//     vector<NewsChannel *> channels;
// public:
//     void addChannel(NewsChannel *channel) override
//     {
//         channels.push_back(channel);
//     }
//     void removeChannel(NewsChannel *channel) override
//     {
//         channels.erase(remove(channels.begin(), channels.end(), channel), channels.end());
//     }
//     void broadcast(const string &news) override
//     {
//         for (auto it : channels)
//         {
//             it->update(news);
//         }
//     }
// };
// // concrete observer
// class SportChannel : public NewsChannel
// {
// public:
//     void update(const string &news) override
//     {
//         cout << "sport channel: " << news << endl;
//     }
// };
// class WeatherChannel : public NewsChannel
// {
// public:
//     void update(const string &news) override
//     {
//         cout << "Weather channel: " << news << endl;
//     }
// };

// Chat application
// observer
class Client
{
public:
    virtual void recieveMessage(const string &message) = 0;
    virtual ~Client() = default;
};
// subject
class ChatServer
{
private:
    vector<Client *> clients;

public:
    void connect(Client *client)
    {
        clients.push_back(client);
    }
    void disconnect(Client *client)
    {
        clients.erase(remove(clients.begin(), clients.end(), client), clients.end());
    }
    void sendMessage(const string &message)
    {
        for (auto it : clients)
        {
            it->recieveMessage(message);
        }
    }
};
class User : public Client
{
private:
    string name;

public:
    User(const string &name) : name(name) {}
    void recieveMessage(const string &message) override
    {
        cout << name << " recieved: " << message << endl;
    }
};

int main()
{
    User user1("kullu");
    User user2("Kuldeep");
    ChatServer server;

    server.connect(&user1);
    server.connect(&user2);
    server.sendMessage("Hello, everyone!");
    server.disconnect(&user2);
    server.sendMessage("see you all tomorrow");
    // client code for chat application

    // client code for news Agency system
    // SportChannel sportChannel;
    // WeatherChannel weatherChannel;
    // Agency newsAgency;
    // newsAgency.addChannel(&sportChannel);
    // newsAgency.addChannel(&weatherChannel);
    // newsAgency.broadcast("Breaking new hurrah India wins");
    // newsAgency.broadcast("WeatherNews: enjoy the day");
    // newsAgency.removeChannel(&sportChannel);
    // newsAgency.broadcast("no sunrise in panchmarhi");

    // client code for stock
    // StockMarket stockMarket;
    // Investor investor1("kullu");
    // Investor investor2("shibhu");
    // stockMarket.attach(&investor1);
    // stockMarket.attach(&investor2);
    // stockMarket.setStockPrice("HCL", 20.90);
    // stockMarket.setStockPrice("Wipro ltd", 208.9);
    // stockMarket.detach(&investor1);
    // stockMarket.setStockPrice("Infosys", 920.90);

    //     WeatherData weatherData;
    //     CurrentConditionDisplay currentDisplay;
    //     StatisticsDisplay statisticsDisplay;
    //     weatherData.attach(&currentDisplay);
    //     weatherData.attach(&statisticsDisplay);
    //     weatherData.setMeasurements(25.5, 65, 1013);
    //     weatherData.setMeasurements(26.0, 70, 1012);
    //     weatherData.detach(&currentDisplay);
    //     weatherData.setMeasurements(27.0, 75, 1011);

    return 0;
}