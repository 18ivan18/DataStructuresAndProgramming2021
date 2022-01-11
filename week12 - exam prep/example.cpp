/*



struct TreeNode
{
    int value;
    TreeNode *left = nullptr, *right = nullptr;
};

#include <string>
#include <vector>

// TreeNode *root = createTree("((*2(*5*))1(*3*))", i);

TreeNode *createTree(const std::string &str, int &i)
{
    if (str[i] == '*')
    {
        i++;
        return nullptr;
    }
    if (str[i] == '(')
    {
        i++;
    }
    TreeNode *left = createTree(str, i);
    TreeNode *root = new TreeNode{str[i++] - '0'};
    TreeNode *right = createTree(str, i);
    if (str[i] == ')')
    {
        i++;
    }
    root->left = left;
    root->right = right;
    return root;
}

#include <iostream>

void print(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    print(root->left);
    std::cout << root->value;
    print(root->right);
}

#include <queue>

std::vector<int> rightSideView(TreeNode *root)
{
    std::vector<int> result;
    std::queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (size_t i = 0; i < size; i++)
        {
            TreeNode *v = q.front();
            q.pop();
            // std::cout << v->value << " ";
            if (v->left)
            {
                q.push(v->left);
            }
            if (v->right)
            {
                q.push(v->right);
            }
            if (i == size - 1)
            {
                result.push_back(v->value);
            }
        }
        std::cout << '\n';
    }

    return result;
}

#include <cassert>

bool operator==(std::vector<int> first, std::vector<int> second)
{
    if (first.size() != second.size())
    {
        return false;
    }
    for (size_t i = 0; i < first.size(); i++)
    {
        if (first[i] != second[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int i = 0;
    TreeNode *root = createTree("((*2(*5*))1(*3*))", i);
    assert((rightSideView(root) == std::vector<int>{1, 3, 5}));
}
*/
/*
#include <iostream>
#include <vector>
#include <queue>
#include <list>

bool bfs(const std::vector<std::list<int>> &adjList, int start, int to)
{
    std::vector<int> parent(adjList.size());
    std::queue<int> q;
    std::vector<bool> visited(adjList.size(), false);
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        if (v == to)
        {
            return true;
        }

        for (auto &&u : adjList[v])
        {
            if (!visited[u])
            {
                q.push(u);
                visited[u] = true;
                parent[u] = v;
            }
        }
    }

    return false;
}

void dfs(const std::vector<std::list<int>> &adjList, std::vector<bool> &visited, int v, int to, std::vector<std::vector<int>> &paths, std::vector<int> &path)
{
    visited[v] = true;
    path.push_back(v);
    if (v == to)
    {
        paths.push_back(path);
        path.pop_back();
        return;
    }
    for (const auto &u : adjList[v])
    {
        if (!visited[u])
        {
            dfs(adjList, visited, v, to, paths, path);
        }
    }
    visited[v] = false;
    path.pop_back();
}

void dfs(const std::vector<std::list<int>> &adjList, int start, int to)
{
    std::vector<bool> visited(adjList.size(), false);
    std::vector<std::vector<int>> paths;
    std::vector<int> path;

    dfs(adjList, visited, start, to, paths, path);
}

void dfs(const std::vector<std::list<int>> &adjList, int v, int cmp, std::vector<int> &comps, std::vector<bool> &visited)
{
    visited[v] = true;
    comps[v] = cmp;
    for (const auto &u : adjList[v])
    {
        if (!visited[u])
        {
            dfs(adjList, u, cmp, comps, visited);
        }
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::list<int>> adjList(n);
    // vertex index from 0 to n - 1
    // vertex index from 1 to n
    for (size_t i = 0; i < m; i++)
    {
        int from, to;
        std::cin >> from >> to;
        adjList[from].push_back(to);
        // adjList[--from].push_back(--to);
        // directed graph
        adjList[to].push_back(from);
    }
    std::vector<bool> visited(n, false);
    std::vector<int> connectedComponents(n);
    int cmp = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(adjList, i, cmp, connectedComponents, visited);
            cmp++;
        }
    }
    // connectedComponents[i] == connectedComponents[j]; // i and j are in the same connected component
    for (size_t connectedComponentIndex = 0; connectedComponentIndex < cmp; connectedComponentIndex++)
    {
        for (size_t v = 0; v < n; v++)
        {
            if (connectedComponents[v] == connectedComponentIndex)
            {
                std::cout << v << " ";
            }
        }
        std::cout << '\n';
    }
}
*/

#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <iostream>
#include <list>
#include <queue>

bool bfs(const std::unordered_map<std::string, std::list<std::string>> &adjList, std::string start, std::string end)
{
    std::queue<std::string> q;
    std::unordered_map<std::string, bool> visited;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        std::string v = q.front();
        q.pop();
        if (v == end)
        {
            return true;
        }
        for (const std::string &u : adjList.at(v))
        {
            if (!visited[u])
            {
                q.push(u);
            }
        }
    }
    return false;
}

int main()
{
    // std::map<int, std::string> m;
    // m.insert({25, "Varna"});
    // m.insert({5, "Sofia"});
    // m.insert({1, "Plovidv"});
    // m[30] = "Burgas";
    // for (const std::pair<int, std::string> &i : m)
    // {
    //     std::cout << i.first << " " << i.second << '\n';
    // }
    // if (m.find(25) != m.end())
    // {
    //     std::cout << (*(m.find(25))).second << '\n';
    // }
    // if (m.find(26) != m.end())
    // {
    //     std::cout << (*(m.find(25))).second << '\n';
    // }
    // std::cout << m[27] << '\n';
    // std::cout << m.at(27) << '\n';

    // std::unordered_map<int, std::string> m;
    // m.insert({25, "Varna"});
    // m.insert({5, "Sofia"});
    // m.insert({1, "Plovidv"});
    // m[30] = "Burgas";
    // for (const std::pair<int, std::string> &i : m)
    // {
    //     std::cout << i.first << " " << i.second << '\n';
    // }
    // if (m.find(25) != m.end())
    // {
    //     std::cout << (*(m.find(25))).second << '\n';
    // }
    // if (m.find(26) != m.end())
    // {
    //     std::cout << (*(m.find(25))).second << '\n';
    // }
    // std::cout << m[27] << '\n';
    // std::cout << m.at(27) << '\n';

    std::unordered_map<std::string, std::list<std::string>> adjList;
    std::string from, to;
    int n, m;
    std::cin >> n >> m;
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> from >> to;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
    std::cin >> from >> to;
    std::cout << std::boolalpha << bfs(adjList, from, to) << '\n';
}