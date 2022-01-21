#include <iostream>
#include <unordered_map>

template <typename T>
class Counter
{
private:
    std::unordered_map<T, int> elementToCount;

public:
    void operator+=(const T &x)
    {
        elementToCount[x]++;
    }
    Counter &operator+(const T &x)
    {
        elementToCount[x]++;
        return *this;
    }
    void operator-=(const T &x)
    {
        if (elementToCount.find(x) != elementToCount.end())
        {
            if (elementToCount[x] != 1)
            {
                elementToCount[x]--;
            }
            else
            {
                elementToCount.erase(x);
            }
        }
    }
    Counter &operator-(const T &x)
    {
        if (elementToCount.find(x) != elementToCount.end())
        {
            if (elementToCount[x] != 1)
            {
                elementToCount[x]--;
            }
            else
            {
                elementToCount.erase(x);
            }
        }
        return *this;
    }
    int count() { return elementToCount.size(); }
    int operator[](const T &x)
    {
        if (elementToCount.find(x) != elementToCount.end())
        {
            return elementToCount.at(x);
        }
        return 0;
    }
    Counter &operator+(const Counter &other)
    {
        for (const auto &pair : other.elementToCount)
        {
            elementToCount[pair.first] += pair.second;
        }

        return *this;
    }
};

int main()
{
    Counter<int> c, c1;
    c += 0;
    c += 0;
    c1 += -2;
    c1 += 0;
    c = c + c1;
    c -= -2;
    std::cout << c[0] << ", " << c[1] << ", " << c[-2] << " - count" << c.count() << '\n';
}