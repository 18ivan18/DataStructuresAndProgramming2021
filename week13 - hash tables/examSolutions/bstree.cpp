template <typename T>
struct BinTreeNode
{
    T data;
    BinTreeNode *left, *right;
};

#include <cassert>
#include <vector>
#include <iostream>

template <typename T>
BinTreeNode<T> *create(const std::string &s, int &i)
{
    const int start = i; // start index of val
    if (s[i] == '-')
    {
        ++i;
    }
    while (i < s.length() && isdigit(s[i]))
    {
        ++i;
    }

    const int val = stoi(s.substr(start, i - start));
    BinTreeNode<T> *root = new BinTreeNode<T>{val};

    // left child
    if (i < s.length() && s[i] == '(')
    {
        ++i; // '('
        root->left = create<int>(s, i);
        ++i; // ')'
    }

    // right child
    if (i < s.length() && s[i] == '(')
    {
        ++i; // '('
        root->right = create<int>(s, i);
        ++i; // ')'
    }

    return root;
}

template <typename T>
BinTreeNode<T> *create(const std::string &s)
{
    if (s.empty())
    {
        return nullptr;
    }
    int i = 0;
    return create<int>(s, i);
}

#include <queue>
#include <unordered_set>

template <typename T>
bool equalSumLevels(BinTreeNode<T> *root)
{
    std::queue<BinTreeNode<T> *> q;
    q.push(root);
    std::unordered_set<T> sums;
    while (!q.empty())
    {
        T sum = T(), size = q.size();
        for (size_t i = 0; i < size; i++)
        {
            BinTreeNode<T> *node = q.front();
            q.pop();
            sum += node->data;
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        if (sums.find(sum) != sums.end())
        {
#ifdef _DEBUG
            std::cout << sum << '\n';
#endif
            return true;
        }
        sums.insert(sum);
    }
    return false;
}

void runTests()
{
    assert(equalSumLevels(create<int>("7(4(1)(5))(10(8))")) == true);
    assert(equalSumLevels(create<int>("7(4(1)(6))(10)")) == true);

    std::cout << "All tests ran successfully\n";
}

int main()
{
    runTests();
}