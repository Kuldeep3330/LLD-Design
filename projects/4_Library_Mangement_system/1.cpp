#include <bits/stdc++.h>
using namespace std;

// library management system
//  This is a simple library management system that allows users to borrow and return books.
class Book
{
public:
    int id;
    string title, author;
    bool isAvailable = true;

    bool operator==(const Book &other) const
    {
        return id == other.id;
    }
};

class User
{
public:
    int id;
    string name;
    vector<Book *> borrowedBooks;

    void borrowBook(Book *book)
    {
        if (book->isAvailable)
        {
            borrowedBooks.push_back(book);
            book->isAvailable = false;
        }
        else
        {
            cout << "Book is not available" << endl;
        }
    }

    void returnBook(Book *book)
    {
        book->isAvailable = true;
        borrowedBooks.erase(
            remove(borrowedBooks.begin(), borrowedBooks.end(), book),
            borrowedBooks.end());
    }
};

class Library
{
public:
    vector<Book> books;
    vector<User> users;

    void addBook(const Book &book)
    {
        books.push_back(book);
    }

    void removeBook(int id)
    {
        auto it = remove_if(books.begin(), books.end(), [&](Book &b)
                            { return b.id == id; });
        if (it != books.end())
        {
            books.erase(it, books.end());
        }
        else
        {
            cout << "Book not found" << endl;
        }
    }

    Book *searchBook(const string &title)
    {
        for (auto &book : books)
        {
            if (book.title == title)
                return &book;
        }
        return nullptr;
    }
};
int main()
{
    Library library;
    library.addBook({1, "C++ Programming", "Bjarne Stroustrup"});
    library.addBook({2, "Data Structures", "Robert Lafore"});

    User user1 = {1, "Alice"};
    User user2 = {2, "Bob"};

    library.users.push_back(user1);
    library.users.push_back(user2);

    Book *bookToBorrow = library.searchBook("C++ Programming");
    if (bookToBorrow)
    {
        library.users[0].borrowBook(bookToBorrow);
        cout << library.users[0].name << " borrowed " << bookToBorrow->title << endl;
    }

    Book *bookToReturn = library.searchBook("C++ Programming");
    if (bookToReturn)
    {
        library.users[0].returnBook(bookToReturn);
        cout << library.users[0].name << " returned " << bookToReturn->title << endl;
    }

    library.removeBook(1);
    cout << "Book with ID 1 removed" << endl;

    Book *bookToSearch = library.searchBook("C++ Programming");
    if (bookToSearch)
    {
        cout << "Book found: " << bookToSearch->title << endl;
    }
    else
    {
        cout << "Book not found" << endl;
    }

    return 0;
}
