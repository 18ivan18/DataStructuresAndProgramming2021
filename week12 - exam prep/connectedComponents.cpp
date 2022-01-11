#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>

void dfs(const std::vector<std::list<int>> &adjList, std::vector<bool> &visited, int v, int cmp,
         std::vector<int> &connectedComponent)
{
    visited[v] = true;
    connectedComponent[v] = cmp;
    for (const auto &u : adjList[v])
    {
        if (!visited[u])
        {
            dfs(adjList, visited, u, cmp, connectedComponent);
        }
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::list<int>> adjList(n);
    for (size_t i = 0; i < m; i++)
    {
        int from, to;
        std::cin >> from >> to;
        adjList[--from].push_back(--to);
        adjList[to].push_back(from);
    }

    std::vector<int> topValues(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> topValues[i];
    }

    std::vector<bool> visited(n, false);
    std::vector<int> connectedComponent(n);
    int cmp = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(adjList, visited, i, cmp, connectedComponent);
            cmp++;
        }
    }

    int sum = 0;
    for (size_t i = 0; i < cmp; i++)
    {
        int index = 0;
        // why no index :cry:
        sum += std::accumulate(
            topValues.begin(), topValues.end(),
            INT32_MAX, [&](const int &result, const int &curr)
            {
                if (connectedComponent[index++] != i)
                {
                    return result;
                }
                return std::min(result, curr);
            });
    }
    std::cout << sum << '\n';
}