#include <vector>
#include <iostream>
struct TreeNode
{
    int data;
    std::vector<TreeNode *> children;

    friend std::ostream &operator<<(std::ostream &os, TreeNode root)
    {
        os << '[' << root.data;
        for (auto &&i : root.children)
        {
            os << " " << *i;
        }

        os << ']';
        return os;
    }
};

#include <sstream>

void moreThan(TreeNode *root, int threshold)
{

    for (auto &&child : root->children)
    {
        if (child->data > threshold)
        {
            std::cout << child->data << " ";
        }
        moreThan(child, threshold);
    }
}

void removeChild(TreeNode *root)
{
    for (auto it = root->children.begin(); it != root->children.end(); it++)
    {
        if ((*it)->data % 2 == 0)
        {
            root->children.erase(it);
            return;
        }
    }

    throw "No even child found.\n";
}

void runProgram(const std::string &instructions, TreeNode *root)
{
    std::stringstream ss(instructions);
    std::string instruction;
    while (ss >> instruction)
    {
        if (instruction[0] == '>')
        {
            moreThan(root, std::stoi(instruction.substr(1)));
        }
        if (instruction[0] == '(' && instruction.back() == ')')
        {
            root = root->children[std::stoi(instruction.substr(1, instruction.size() - 2)) - 1];
        }
        if (instruction[0] = 'e' && instruction[1] == '(' && instruction.back() == ')')
        {
            removeChild(root);
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode{
        10,
        {new TreeNode{20}, new TreeNode{
                               30,
                               {new TreeNode{5}, new TreeNode{35}, new TreeNode{8, {new TreeNode{70}}}}}}};
    std::cout << *root << '\n';
    std::string instructions = "(2) >8";
    runProgram(instructions, root);
}