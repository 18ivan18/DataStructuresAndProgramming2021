#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <cassert>

int hemingDistance(std::string a, std::string b)
{

    int min = std::min(a.size(), b.size()), dif = abs(b.size() - a.size());
    for (size_t i = 0; i < min; i++)
    {
        if (a[i] != b[i])
        {
            dif++;
        }
    }
    return dif;
}

void runTests()
{
    assert(hemingDistance("abcd", "xbdc") == 3);
    assert(hemingDistance("abcdef", "abc") == 3);

    std::cout << "All tests ran successfully\n";
}

void dfs(std::unordered_map<std::string, std::list<std::string>> &adjList, std::unordered_map<std::string, bool> &visited, const std::string &to, const std::string &v, int current, int &shortest)
{
    visited[v] = true;
    if (v == to)
    {
        shortest = std::min(shortest, current);
        visited[v] = false;
        return;
    }
    for (const auto &u : adjList[v])
    {
        if (!visited[u])
        {
            dfs(adjList, visited, to, u, current + hemingDistance(u, v), shortest);
        }
    }
    visited[v] = false;
}

int main()
{
#ifdef _DEBUG
    runTests();
#endif
    std::unordered_map<std::string, std::list<std::string>> adjList;
    std::unordered_map<std::string, bool> visited;
    int n;
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::string v;
        std::cin >> v;
        adjList.insert({v, std::list<std::string>()});
    }
    int m;
    std::cin >> m;
    std::string from, to;
    while (std::cin >> from >> to)
    {
        adjList.at(from).push_back(to);
        adjList.at(to).push_back(from);
    }
#ifdef _DEBUG
    for (const auto &pair : adjList)
    {
        std::cout << pair.first << ":";
        for (auto &&j : pair.second)
        {
            std::cout << j << " ";
        }
        std::cout << '\n';
    }
#endif
    std::cin >> from >> to;
    int shortestPath = INT32_MAX;
    dfs(adjList, visited, to, from, 0, shortestPath);
    std::cout << "Shortest path length: " << shortestPath << "\n";
}