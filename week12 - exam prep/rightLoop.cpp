#include <iostream>
#include <vector>
#include <queue>
#include <string>

template <typename T>
bool vectorEquality(const std::vector<T> v1, const std::vector<T> v2)
{
    if (v1.size() != v2.size())
    {
        return false;
    }
    for (size_t i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

struct TreeNode
{
    int value;
    TreeNode *left = nullptr, *right = nullptr;

    TreeNode(int value) : value{value} {}
};

std::vector<int> rightSideView(TreeNode *root)
{
    if (!root)
    {
        return {};
    }
    std::vector<int> solution;
    std::queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty())
    {
        int size = queue.size();
        while (size > 0)
        {
            TreeNode *current = queue.front();
            queue.pop();
            if (current->left != nullptr)
            {
                queue.push(current->left);
            }
            if (current->right != nullptr)
            {
                queue.push(current->right);
            }
            if (size == 1)
            {
                solution.push_back(current->value);
            }
            size--;
        }
    }
    return solution;
}

TreeNode *createTree(std::string s, int &index)
{
    TreeNode *leftSubtree, *rightSubtree, *tree;
    if (s.at(index) == '(')
    {
        index++;
        leftSubtree = createTree(s, index);
    }

    if (s.at(index) == '*')
    {
        index++;
        return nullptr;
    }
    int startIdx = index;
    while (isdigit(s.at(index)))
    {
        index++;
    }
    tree = new TreeNode(std::stoi(s.substr(startIdx, index - startIdx)));

    rightSubtree = createTree(s, index);

    if (s.at(index) == ')')
    {
        index++;
    }
    tree->left = leftSubtree;
    tree->right = rightSubtree;

    return tree;
}

void inorder(TreeNode *root, std::vector<int> &arr)
{
    if (!root)
    {
        return;
    }
    inorder(root->left, arr);
    arr.push_back(root->value);
    inorder(root->right, arr);
}

#include <cassert>

void runTests()
{
    assert(vectorEquality(std::vector<int>{1, 2, 3}, {1, 2, 3}));
    int i = 0;
    TreeNode *t = createTree("((*2(*5*))1(*3*))", i);
    std::vector<int> inord;
    inorder(t, inord);
    assert(vectorEquality(inord, {2, 5, 1, 3}));
    assert(vectorEquality(rightSideView(t), {1, 3, 5}));

    std::cout << "All tests ran successfully\n";
}

int main()
{
    runTests();
}