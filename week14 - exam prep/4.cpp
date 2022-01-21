#include <iostream>
#include <vector>
#include <list>
#include <queue>

bool twoWayN(const std::vector<std::list<int>> &adjList, int start, int len)
{
    std::vector<bool> visited(adjList.size(), false);
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        len--;
        if (len < 0)
        {
            return true;
        }
        int size = q.size();
        for (size_t i = 0; i < size; i++)
        {
            int v = q.front();
            q.pop();
            for (int u : adjList[v])
            {
                if (!visited[u])
                {
                    q.push(u);
                    visited[u] = true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<bool>> adjMatrix(n, std::vector<bool>(m, false));
    std::vector<std::list<int>> adjList(n);

    for (size_t i = 0; i < m; i++)
    {
        int from, to;
        std::cin >> from >> to;
        adjMatrix[from][to] = true;
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (adjMatrix[i][j] == true && adjMatrix[j][i] == true)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
#ifdef _DEBUG
    for (size_t i = 0; i < adjList.size(); i++)
    {
        std::cout << i << ": ";
        for (auto &&v : adjList[i])
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
#endif

    int start, l;
    std::cin >> start >> l;
    std::cout << std::boolalpha << twoWayN(adjList, start, l) << '\n';
}