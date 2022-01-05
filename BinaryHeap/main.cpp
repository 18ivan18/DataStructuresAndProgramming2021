#include <iostream>
#include "MaxPQ.cpp"
#include <string>

#define TYPE int

int main()
{
    MaxPQ<TYPE> pq;
    std::string word;
    try
    {
        while (std::cin >> word)
        {
            if (word.compare("-") == 0)
            {
                std::cout << "Max: " << pq.delMax() << "\n";
            }
            else
            {
                int val = stoi(word);
                pq.insert(val);
            }
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}