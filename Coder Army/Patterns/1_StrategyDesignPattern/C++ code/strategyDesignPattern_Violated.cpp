#include <iostream>
using namespace std;

class WalkRobot
{
public:
    virtual void walk() = 0;
};
class NormalWalk : public WalkRobot
{
public:
    void walk() override
    {
        cout << "walking Robot\n";
    }
};

class NoWalk : public WalkRobot
{
public:
    void walk() override
    {
        cout << "non-walking Robot\n";
    }
};

// Interface for talk
class TalkRobot
{
public:
    virtual void talk() = 0;
};
class NormalTalk : public TalkRobot
{
public:
    void talk() override
    {
        cout << "Talking Robot\n";
    }
};

class NoTalk : public TalkRobot
{
public:
    void talk() override
    {
        cout << "non-talking Robot\n";
    }
};
// interface for fly
class FlyRobot
{
public:
    virtual void fly() = 0;
};
class NormalFly : public FlyRobot
{
public:
    void fly() override
    {
        cout << "flying Robot\n";
    }
};

class NoFly : public FlyRobot
{
public:
    void fly() override
    {
        cout << "non-flying Robot\n";
    }
};

// context
class Robot
{
private:
    WalkRobot *walkRobot;
    TalkRobot *talkRobot;
    FlyRobot *flyRobot;

public:
    Robot(WalkRobot *walkRobot, TalkRobot *talkRobot, FlyRobot *flyRobot) : walkRobot(walkRobot), talkRobot(talkRobot), flyRobot(flyRobot) {}

    void walk()
    {
        walkRobot->walk();
    }

    void talk()
    {
        talkRobot->talk();
    }

    void fly()
    {
        flyRobot->fly();
    }

    virtual void projection() = 0;
};

//
class CompanionRobot : public Robot
{
public:
    CompanionRobot(WalkRobot *w, TalkRobot *t, FlyRobot *f) : Robot(w, t, f) {}
    void projection() override
    {
        cout << "Displaying freindly companian features\n";
    }
};

class WorkerRobot : public Robot
{
public:
    WorkerRobot(WalkRobot *w, TalkRobot *t, FlyRobot *f) : Robot(w, t, f) {}
    void projection() override
    {
        cout << "Displaying worker efficiency features\n";
    }
};

int main()
{
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NormalFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    delete robot1;
    delete robot2;

    return 0;
}
