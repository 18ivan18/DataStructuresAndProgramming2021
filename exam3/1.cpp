#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

enum class Color
{
    Orange = 'o',
    YELLOW = 'y',
    RED = 'r',
    GREEN = 'g',
    BLUE = 'b'
};

struct Cloth
{
    int price;
    Color color;

    friend std::ostream &operator<<(std::ostream &os, const Cloth &c)
    {
        os << (char)c.color << "_" << c.price << '$';
        return os;
    }
};

using Shelf = std::vector<std::list<Cloth>>;

void printShelf(Shelf &s)
{
    std::vector<std::size_t> sizes;
    std::transform(s.begin(), s.end(), std::back_inserter(sizes),
                   [](const std::list<Cloth> &c) -> std::size_t
                   { return c.size(); });

    size_t max = std::accumulate(sizes.begin(), sizes.end(),
                                 0,
                                 [](size_t result, size_t curr)
                                 { return std::max(result, curr); });

    std::vector<std::list<Cloth>::iterator> shelves;
    std::transform(s.begin(), s.end(),
                   std::back_inserter(shelves),
                   [](std::list<Cloth> &c)
                   { return c.begin(); });

    // std::cout << max << "\n";
    for (int i = max - 1; i >= 0; i--)
    {
        for (size_t j = 0; j < s.size(); j++)
        {
            if (i < s[j].size())
            {
                std::cout << *shelves[j] << " ";
                shelves[j]++;
            }
            else
            {
                std::cout << '\t';
            }
        }
        std::cout << "\n";
    }
}
#include <unordered_set>

struct ColorHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

void validate(Shelf &s, std::vector<std::unordered_set<Color>> &acceptableColorsByPiles, std::vector<std::pair<int, int>> minMaxPrices)
{
    std::list<Cloth>::iterator curr, next;
    int price;
    for (int i = 0; i < s.size(); i++)
    {
        auto &shelf = s[i];
        if (i < s.size() - 1)
        {
            auto nextShelf = s[i + 1];
            while (shelf.size() && shelf.back().color == nextShelf.back().color)
            {
                shelf.pop_back();
            }
        }
        curr = shelf.begin();
        next = ++shelf.begin();
        price = 0;
        while (curr != shelf.end())
        {
            if (next != shelf.end() && ((*curr).color == (*next).color || acceptableColorsByPiles[i].count((*curr).color) == 0))
            {
                shelf.erase(curr);
                curr = next;
                next++;
            }
            else
            {
                price += (*curr).price;
                curr++;
                next++;
            }
        }
        auto [min, max] = minMaxPrices[i];
        if (price < min)
        {
            // add
            std::cout << "Price underflow\n";
        }
        if (price > max)
        {
            // remove
            std::cout << "Price overflow\n";
        }
    }
}

int main()
{
    Shelf s = {{{10, Color::YELLOW}, {6, Color::RED}, {4, Color::YELLOW}, {15, Color::YELLOW}, {3, Color::RED}, {1, Color::GREEN}, {17, Color::YELLOW}, {20, Color::RED}},
               {{3, Color::BLUE}, {5, Color::RED}, {10, Color::YELLOW}, {25, Color::BLUE}}};
    printShelf(s);
    // std::vector<std::vector<Color>> acceptableColorsByPilesVector = {{Color::YELLOW, Color::RED, Color::GREEN},
    //                                                                  {Color::YELLOW, Color::RED, Color::BLUE}};
    std::vector<std::unordered_set<Color>> acceptableColorsByPiles(s.size());
    acceptableColorsByPiles[0].insert(Color::YELLOW);
    acceptableColorsByPiles[0].insert(Color::RED);
    acceptableColorsByPiles[0].insert(Color::GREEN);
    acceptableColorsByPiles[1].insert(Color::BLUE);
    acceptableColorsByPiles[1].insert(Color::RED);
    acceptableColorsByPiles[1].insert(Color::YELLOW);

    std::vector<std::pair<int, int>>
        minMaxPrices = {{20, 100},
                        {50, 70}};
    validate(s, acceptableColorsByPiles, minMaxPrices);
    printShelf(s);
}