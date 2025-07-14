#include <iostream>
#include <memory>
using namespace std;

/*
traffic light system:
The light can be Red, Yellow, or Green. The behavior of the light changes depending on its current state.
*/
// state interface
class TrafficLightState
{
public:
    virtual void handle() const = 0;
    virtual ~TrafficLightState() {}
};
// // concrete Interfaces
class RedLight : public TrafficLightState
{
public:
    void handle() const override
    {
        cout << "RedLight ON!" << endl;
    }
};
class YellowLight : public TrafficLightState
{
public:
    void handle() const override
    {
        cout << "YellowLight ON!" << endl;
    }
};
class GreenLight : public TrafficLightState
{
public:
    void handle() const override
    {
        cout << "GreenLight ON!" << endl;
    }
};
// // context(The object whose behavior changes based on its state.)
class TrafficLightContext
{
private:
    shared_ptr<TrafficLightState> state;

public:
    void setState(shared_ptr<TrafficLightState> newState)
    {
        state = newState;
    }
    void request() const
    {
        if (state)
        {
            state->handle();
        }
        else
        {
            cout << "No state is set!\n";
        }
    }
};

// Example 2: Document overflow
// state interface
class DocumentState
{
public:
    virtual void handle() const = 0;
    virtual ~DocumentState() = default;
};
// concrete States
class Draft : public DocumentState
{
public:
    void handle() const override
    {
        cout << "Document is in Draft State." << endl;
    }
};
class Review : public DocumentState
{
public:
    void handle() const override
    {
        cout << "Document is under Review." << endl;
    }
};
class Published : public DocumentState
{
public:
    void handle() const override
    {
        cout << "Document is in Published." << endl;
    }
};
// Context
class DocumentContext
{
private:
    shared_ptr<DocumentState> state;

public:
    void setState(shared_ptr<DocumentState> newState)
    {
        state = newState;
    }
    void process() const
    {
        if (state)
        {
            state->handle();
        }
        else
        {
            cout << "No state is set for the document." << endl;
        }
    }
};
int main()
{
    // client code for Document workflow
    DocumentContext doc;

    shared_ptr<DocumentState> draft = make_shared<Draft>();
    shared_ptr<DocumentState> review = make_shared<Review>();
    shared_ptr<DocumentState> published = make_shared<Published>();

    doc.setState(draft);
    doc.process();

    doc.setState(review);
    doc.process();

    doc.setState(published);
    doc.process();

    // client code for Traffic light
    //  TrafficLightContext context;

    // shared_ptr<TrafficLightState> red = make_shared<RedLight>();
    // shared_ptr<TrafficLightState> yellow = make_shared<YellowLight>();
    // shared_ptr<TrafficLightState> green = make_shared<GreenLight>();

    // context.setState(red);
    // context.request();

    // context.setState(green);
    // context.request();

    // context.setState(yellow);
    // context.request();

    return 0;
}
