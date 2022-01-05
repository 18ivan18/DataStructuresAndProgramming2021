#include <vector>
#include <queue>
#include <iostream>
#include <climits>

struct Node
{
    int data;
    Node *left = nullptr, *right = nullptr;
};

int maxpath(Node *root, int sum, int data)
{
    if (!root || root->data > data)
    {
        return 0;
    }
    sum += root->data;

    return std::max(sum, std::max(maxpath(root->left, sum, root->data), maxpath(root->right, sum, root->data)));
}

// void maxpath(Node *root, int &sum, int &max)
// {
//     sum += root->data;
//     if (root->left && root->data < root->left->data)
//     {
//         maxpath(root->left, sum, max);
//     }
//     if (root->right && root->data < root->right->data)
//     {
//         maxpath(root->right, sum, max);
//     }
//     max = std::max(sum, max);
//     sum -= root->data;
// }

int maxpath(Node *root)
{
    int sum = 0;
    return maxpath(root, sum, INT_MAX);
}

int main()
{
    Node *root = new Node{
        1, new Node{2, new Node{3, new Node{1}, new Node{1}}}, new Node{1, new Node{8}, new Node{9}}};
    std::cout << maxpath(root) << std::endl;
}