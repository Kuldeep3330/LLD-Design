
// The Memento Design Pattern is a behavioral design pattern that allows an object's state to be saved and restored at a later point without violating encapsulation.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Memento (Stores the state of the originator.)
class Memento
{
private:
    string state;

public:
    Memento(const string &state) : state(state) {}

    string getState() const
    {
        return state;
    }
};
// originator(The object whose state is saved and restored.)
class Editor
{
private:
    string content;

public:
    void write(const string &text)
    {
        content += text;
    }

    void showContent() const
    {
        cout << "Current Content: " << content << endl;
    }

    Memento save() const
    {
        return Memento(content);
    }

    void restore(const Memento &memento)
    {
        content = memento.getState();
    }
};
// 3.caretaker(Manages mementos to save and restore the originator's state.)

class History
{
private:
    vector<Memento> states;

public:
    void push(const Memento &memento)
    {
        states.push_back(memento);
    }

    Memento pop()
    {
        if (states.empty())
        {
            throw runtime_error("No states to restore.");
        }
        Memento lastState = states.back();
        states.pop_back();
        return lastState;
    }
};
int main()
{
    Editor editor;
    History history;

    editor.write("Hello, ");
    editor.showContent();
    history.push(editor.save());

    editor.write("World!");
    editor.showContent();
    history.push(editor.save());

    editor.write(" This is a new sentence.");
    editor.showContent();

    cout << "Undoing changes...\n";
    editor.restore(history.pop());
    editor.showContent();

    editor.restore(history.pop());
    editor.showContent();

    return 0;
}
