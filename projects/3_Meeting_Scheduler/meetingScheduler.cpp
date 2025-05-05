#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

class Meeting
{
public:
    int start;
    int end;
    string roomName;
    Meeting(int start, int end, const string &roomName) : start(start), end(end), roomName(roomName) {}
};

class MeetingRoom
{
    string name;
    vector<pair<int, int>> bookings;

public:
    MeetingRoom(const string &name) : name(name) {}

    bool isAvailable(int start, int end)
    {
        for (auto &booking : bookings)
        {
            if (!(end <= booking.first || start >= booking.second))
            {
                return false;
            }
        }
        return true;
    }
    void book(int start, int end)
    {
        bookings.push_back({start, end});
    }

    string getName() const
    {
        return name;
    }
};

// Main Meeting Scheduler
class MeetingScheduler
{
    vector<MeetingRoom> rooms;
    vector<Meeting> meetingHistory;

public:
    MeetingScheduler(const vector<string> &roomNames)
    {
        for (auto &name : roomNames)
        {
            rooms.emplace_back(name);
        }
    }

    string bookMeeting(int start, int end)
    {
        for (auto &room : rooms)
        {
            if (room.isAvailable(start, end))
            {
                room.book(start, end);
                meetingHistory.emplace_back(start, end, room.getName());
                return room.getName();
            }
        }
        return "No Room Available\n";
    }

    void printHistory()
    {
        cout << "meeting History\n";
        for (auto &meeting : meetingHistory)
        {
            cout << "Room booked name: " << meeting.roomName << " , start time: " << meeting.start << " , end time: " << meeting.end << "\n";
        }
    }
};

int main()
{
    vector<string> roomNames = {"Alpha", "Beta", "Gamma"};
    MeetingScheduler scheduler(roomNames);
    cout << scheduler.bookMeeting(9, 11) << endl;
    cout << scheduler.bookMeeting(10, 12) << endl;
    cout << scheduler.bookMeeting(9, 11) << endl;
    cout << scheduler.bookMeeting(10, 12) << endl;

    scheduler.printHistory();

    return 0;
}
