#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

struct HTMLNode
{
    std::string tag, text;
    std::vector<HTMLNode *> children;
};

HTMLNode *buildTree(std::ifstream &is, std::stack<std::string> &s)
{
    std::string input, content;
    std::getline(is, input, '>');
    if (input.size() != 0 && input[0] == '/')
    {
        return nullptr;
    }

    HTMLNode *root = new HTMLNode();
    root->tag = input;
    std::getline(is, content, '<');
    if (content.length() == 0 || !isspace(content[0]))
    {
        root->text = content;
        // std::cout << content << '\n';
    }
    HTMLNode *child = buildTree(is, s);
    while (child != nullptr)
    {
        root->children.push_back(child);
        child = buildTree(is, s);
    }
    is.ignore(100, '<');
    return root;
}

void checkHTMLFile(const std::string &name)
{
    std::ifstream is(name);
    if (!is)
    {
        throw std::invalid_argument("Opening file error");
    }
    std::stack<std::string> s;
    is.ignore(100, '<');
    std::string input, content;
    while (std::getline(is, input, '>'))
    {
        std::getline(is, content, '<');
        if (!isspace(content[0]))
        {
            std::cout << content << '\n';
        }
        else
        {
            // throw std::invalid_argument("Invalid content in a tag node");
        }
        if (input[0] == '/')
        {
            if (s.empty())
            {
                throw std::invalid_argument("Tag that is not opened closes");
            }
            if (s.top() == input.substr(1))
            {
                s.pop();
            }
            else
            {
                throw std::invalid_argument("...");
            }
        }
        else
        {
            if (std::find_if(input.begin(), input.end(), [](const char &c)
                             { return !(c >= 'a' && c <= 'z' || isdigit(c)); }) != input.end())
            {
                throw std::invalid_argument("Tag name does not consist of only small letters and numbers.");
            }
            s.push(input);
        }
    }
    if (!s.empty())
    {
        throw std::invalid_argument("Opened tag is not closed");
    }
}

void formatTree(HTMLNode *root, int level)
{
    for (size_t i = 0; i < level * 4; i++)
    {
        std::cout << ' ';
    }
    if (root->children.empty())
    {
        if (!root->text.empty())
        {
            std::cout << '<' << root->tag << '>' << root->text << "</" << root->tag << ">\n";
        }
        return;
    }
    else
    {
        std::cout << '<' << root->tag << ">" << root->text << '\n';
        for (auto &&i : root->children)
        {
            formatTree(i, level + 1);
        }
    }

    for (size_t i = 0; i < level * 4; i++)
    {
        std::cout << ' ';
    }
    std::cout << "</" << root->tag << ">\n";
}

#include <cassert>

int main()
{
    try
    {
        checkHTMLFile("index.html");
        std::cout << "correct\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        std::cout << "incorrect\n";
    }

    std::ifstream is("index.html");
    is.ignore(100, '<');
    std::stack<std::string> s;
    HTMLNode *root = buildTree(is, s);
    formatTree(root, 0);
}