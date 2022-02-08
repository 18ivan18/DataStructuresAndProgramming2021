#include <iostream>
#include <vector>
#include <queue>
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

using Shelf = std::vector<std::deque<Cloth>>;

void printShelf(Shelf s)
{
    std::vector<std::size_t> sizes;
    std::transform(s.begin(), s.end(), std::back_inserter(sizes),
                   [](const std::deque<Cloth> &c) -> std::size_t
                   { return c.size(); });

    size_t max = std::accumulate(sizes.begin(), sizes.end(),
                                 0,
                                 [](size_t result, size_t curr)
                                 { return std::max(result, curr); });

    // std::cout << max << "\n";
    for (int i = max - 1; i >= 0; i--)
    {
        for (size_t j = 0; j < s.size(); j++)
        {
            if (i < s[j].size())
            {
                std::cout << s[j].front() << " ";
                s[j].pop_front();
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

Color getAvailableColor(Color c, const std::unordered_set<Color> &acceptableColors)
{
    for (auto &&color : acceptableColors)
    {
        if (color != c)
        {
            return color;
        }
    }
    throw "No color available.";
}

void validate(Shelf &s, std::vector<std::unordered_set<Color>> &acceptableColorsByPiles, std::vector<std::pair<int, int>> minMaxPrices)
{
    int price;
    for (int i = 0; i < s.size(); i++)
    {
        std::deque<Cloth> shelf = s[i], newShelf;
        if (i < s.size() - 1)
        {
            auto nextShelf = s[i + 1];
            while (shelf.size() && shelf.back().color == nextShelf.back().color)
            {
                shelf.pop_back();
            }
        }
        price = 0;
        while (!shelf.empty())
        {
            auto item = shelf.front();
            shelf.pop_front();
            if (!shelf.empty() && (item.color == shelf.front().color || !acceptableColorsByPiles[i].count(item.color)))
            {
                continue;
            }

            newShelf.push_back(item);
            price += item.price;
        }
        auto [min, max] = minMaxPrices[i];
        if (price < min)
        {
            Color c = getAvailableColor(newShelf.front().color, acceptableColorsByPiles[i]);
            newShelf.push_front({min - price, c});
        }
        s[i] = newShelf;
        // I don't like this approach for dealing with the price overflow, we do it this way so when we remove the last item we don't introduce new problems with the colros of the bottom cloth of the stacks
        if (price > max)
        {
            s[i].pop_back();
            i--;
        }
    }
}

int main()
{
    Shelf s = {{{10, Color::YELLOW}, {6, Color::RED}, {4, Color::YELLOW}, {15, Color::YELLOW}, {3, Color::RED}, {1, Color::GREEN}, {17, Color::YELLOW}, {20, Color::RED}},
               {{3, Color::BLUE}, {5, Color::RED}, {10, Color::YELLOW}, {25, Color::BLUE}}};
    printShelf(s);
    std::vector<std::unordered_set<Color>> acceptableColorsByPiles(s.size());
    acceptableColorsByPiles[0].insert(Color::YELLOW);
    acceptableColorsByPiles[0].insert(Color::RED);
    acceptableColorsByPiles[0].insert(Color::GREEN);
    acceptableColorsByPiles[1].insert(Color::BLUE);
    acceptableColorsByPiles[1].insert(Color::RED);
    acceptableColorsByPiles[1].insert(Color::YELLOW);

    std::vector<std::pair<int, int>>
        minMaxPrices = {{20, 50},
                        {50, 70}};
    validate(s, acceptableColorsByPiles, minMaxPrices);
    printShelf(s);
}