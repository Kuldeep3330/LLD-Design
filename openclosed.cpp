#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
// #include<boost/lexical_cast.hpp>

using namespace std;
// using namespace boost;

enum class Color
{
    red,
    green,
    blue
};
enum class Size
{
    small,
    medium,
    large
};
struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{
    vector<Product *> by_color(vector<Product *> items, Color color)
    {
        vector<Product *> result;
        for (auto &i : items)
            if (i->color == color)
                result.push_back(i);
        return result;
    }
};
int main()
{
    return 0;
}