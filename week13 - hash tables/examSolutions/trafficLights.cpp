#include <iostream>
#include <vector>
#include <list>
#include <cassert>
#include <string>

void changeLight(int n, std::vector<bool> &isGreedLight)
{
    isGreedLight[n] = !isGreedLight[n];
}

#include <queue>

bool bfs(const std::vector<std::list<int>> &adjList, const std::vector<bool> &isGreedLight, int from, int to)
{
    std::queue<int> q;
    std::vector<bool> visited(adjList.size(), false);
    visited[from] = true;
    q.push(from);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (v == to)
        {
            return true;
        }
        for (auto &&i : adjList[v])
        {
            if (!visited[i] && isGreedLight[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return false;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::list<int>> adjList(n);
    std::vector<bool> isGreedLight(n, false);
    for (size_t i = 0; i < m; i++)
    {
        int from, to;
        std::cin >> from >> to;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
    int q;
    std::cin >> q;
    for (size_t i = 0; i < q; i++)
    {
        std::string input;
        std::cin >> input;
        if (input == "change")
        {
            int n;
            std::cin >> n;
            changeLight(n, isGreedLight);
        }
        if (input == "path")
        {
            int from, to;
            std::cin >> from >> to;
            std::cout << "searhing for path between " << from << " " << to << '\n';
            std::cout << std::boolalpha << bfs(adjList, isGreedLight, from, to) << '\n';
        }
    }
}