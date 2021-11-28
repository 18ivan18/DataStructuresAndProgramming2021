#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int value;
    int size;
    vector<Node *> nodes;
};

int counter(Node *node)
{
    int sum = node->nodes.size();
    for (auto i : node->nodes)
    {
        sum += counter(i);
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    Node **nodes = new Node *[n];
    for (int i = 0; i < n; i++)
    {
        nodes[i] = new Node{i};
    }

    for (size_t i = 0; i < n - 1; i++)
    {
        int parent;
        int child;
        cin >> parent >> child;
        nodes[parent]->nodes.push_back(nodes[child]);
    }

    for (size_t i = 0; i < n; i++)
    {
        cout << counter(nodes[i]) << " ";
    }
}