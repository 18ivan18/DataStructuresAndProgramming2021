template <typename T>
struct BinTreeNode
{
    T data;
    BinTreeNode<T> *left, *right;
};

#include <string>
#include <unordered_set>
struct ArithmeticBinTree : public BinTreeNode<std::string>
{
    ArithmeticBinTree *left, *right;
    float result;
    ArithmeticBinTree(std::string data, ArithmeticBinTree *left = nullptr, ArithmeticBinTree *right = nullptr) : left{left}, right{right}
    {
        this->data = data;
    }
};

std::unordered_set<std::string> operations;

bool isOp(const std::string &op)
{
    return operations.count(op) == 1;
}

bool matchWithAccuracy(float first, float second, float accuracy)
{
    return std::abs(first - second) < accuracy;
}

float apply(float first, std::string op, float second)
{
    if (op == "+")
    {
        return first + second;
    }
    if (op == "-")
    {
        return first - second;
    }
    if (op == "*")
    {
        return first * second;
    }
    if (op == "/")
    {
        return first / second;
    }
    throw std::invalid_argument("Unrecognized operator.\n");
}

ArithmeticBinTree *match(float result, float accuracy, ArithmeticBinTree *root)
{
    if (!isOp(root->data))
    {
        root->result = std::stof(root->data);
        return matchWithAccuracy(root->result, result, accuracy) ? root : nullptr;
    }
    if (match(result, accuracy, root->left))
    {
        return root->left;
    }
    if (match(result, accuracy, root->right))
    {
        return root->right;
    }
    root->result = apply(root->left->result, root->data, root->right->result);
    return matchWithAccuracy(root->result, result, accuracy) ? root : nullptr;
}

#include <iostream>

int main()
{
    operations.insert("+");
    operations.insert("-");
    operations.insert("*");
    operations.insert("/");
    ArithmeticBinTree *root = new ArithmeticBinTree("+", new ArithmeticBinTree("3"), new ArithmeticBinTree("*", new ArithmeticBinTree("+", new ArithmeticBinTree("5"), new ArithmeticBinTree("9")), new ArithmeticBinTree("2")));
    ArithmeticBinTree *m = match(27.95, 0.1, root);
    std::cout << m->result << '\n';
}