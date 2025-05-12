#include <bits/stdc++.h>
using namespace std;
// observer design pattern

// NotifiactionSystem tightly depends on each type of observer

class NotificationSystem
{
public:
    void weatherChanged(int temp)
    {
        displayTemp(temp);
        logTemp(temp);
    }
    void displayTemp(int temp)
    {
        cout << "Temperature is " << temp << endl;
    }
    void logTemp(int temp)
    {
        cout << "Temperature logged " << temp << endl;
    }
};
// ❌Hard to add/remove new observers(eg. email, SMS, etc.)
// ❌Tightly coupled with the NotificationSystem class
// ❌Difficult to maintain and extend
// ❌Difficult to test
// ❌NotificationSystem must know every observer explicity.

int main()
{
    NotificationSystem notificationSystem;
    notificationSystem.weatherChanged(30);
    return 0;
}
