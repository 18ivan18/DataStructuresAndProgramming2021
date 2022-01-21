#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

const int MAX_DISTANCE = INT32_MAX;

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

struct Edge
{
    int to;
    long long value;

    Edge(int to, long long value)
    {
        this->to = to;
        this->value = value;
    }
};

#include <unordered_map>

int main()
{
    int verticesCount;
    std::cin >> verticesCount;
    std::unordered_map<std::string, int> verticesMap;
    std::unordered_map<int, std::string> indexToVertex;
    for (size_t i = 0; i < verticesCount; i++)
    {
        std::string v;
        std::cin >> v;
        verticesMap.insert({v, i});
        indexToVertex.insert({i, v});
    }

    std::vector<std::vector<Edge>> graph(verticesCount, std::vector<Edge>());

    int edgesCount;
    std::cin >> edgesCount;

    std::string from, to;
    for (int i = 0; i < edgesCount; i++)
    {
        std::cin >> from >> to;
        int value = hemingDistance(from, to), fromIdx = verticesMap.at(from), toIdx = verticesMap.at(to);
        graph[fromIdx].push_back(Edge(toIdx, value));
    }

#ifdef _DEBUG
    for (size_t i = 0; i < graph.size(); i++)
    {
        std::cout << i << " " << indexToVertex.at(i) << ": ";
        for (auto &&e : graph[i])
        {
            std::cout << e.to << " (" << indexToVertex.at(e.to) << ", " << e.value << "), ";
        }
        std::cout << '\n';
    }
#endif

    std::vector<int> possiblePaths(verticesCount, 0);
    std::vector<int> distances(verticesCount, MAX_DISTANCE);

    std::cin >> from >> to;
    int sourceNode = verticesMap.at(from), destinationNode = verticesMap.at(to);

    distances[sourceNode] = 0;
    possiblePaths[sourceNode] = 1;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> priorityQueue;
    priorityQueue.push({0, sourceNode});
    std::vector<bool> visited(verticesCount);

    while (!priorityQueue.empty())
    {
        auto [distanceToCurrent, nearestNode] = priorityQueue.top();
        priorityQueue.pop();

        if (visited[nearestNode])
        {
            continue;
        }

        visited[nearestNode] = true;

        for (const Edge &child : graph[nearestNode])
        {
            int node = child.to, currentMinDistance = distanceToCurrent + child.value;

            if (currentMinDistance < distances[node])
            {
                distances[node] = currentMinDistance;
                possiblePaths[node] = possiblePaths[nearestNode];

                priorityQueue.push({currentMinDistance, node});
            }
            else if (currentMinDistance == distances[node])
            {
                possiblePaths[node] += possiblePaths[nearestNode];
            }
        }
    }

    if (distances[destinationNode] == MAX_DISTANCE)
    {
        std::cout << -1 << " " << 0;
        return 0;
    }

    std::cout << distances[destinationNode] << " " << possiblePaths[destinationNode] << '\n';
}