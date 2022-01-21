#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <iostream>

// callable class
template <size_t N>
class PlusN
{
public:
    int operator()(int a)
    {
        return a + N;
    }
};

class compCallable
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

#include <string>
#include <algorithm>

int comp(int, int)
{
    return -1;
}

class Person
{
private:
    std::string name;

public:
    Person(std::string name) : name{name} {};
    ~Person();
};

// 2 5 7 10 19

int main()
{
    int increment = 10;
    PlusN<10> po;
    std::cout << po(5) << '\n';
    std::cout << std::hash<std::string>()("asd") << '\n';

    std::map<int, int> studentIdToGradeMap;                    // O(logn) -> ordered
    std::unordered_map<int, int> studentIdToGradeUnorderedMap; // O(1)    -> unordered
    std::set<int> sums;                                        // O(logn) -> ordered
    std::unordered_set<int> sumsUnorderedSet;                  // O(1)    -> unordered

    int arr[] = {9, 2, 3, 5, 1, 7, 4}, size = sizeof(arr) / sizeof(arr[0]);
    std::sort(arr, arr + size, [&](int a, int b)
              {
                  std::cout << studentIdToGradeMap[increment++] << '\n';
                  return a > b;
              });
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';

    std::string name = "Ivan";
    name += " e prepodavatel\n";
    std::cout << name;

    Person ivan("Ivan");
}