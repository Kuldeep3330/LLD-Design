#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual T next() = 0;
    virtual ~Iterator() = default;
};

// concrete Iterator
template <typename T>
class ListIterator : public Iterator<T>
{
    vectro<T> &data;
    size_t index;

public:
    ListIterator(vector<T> &vec)
};