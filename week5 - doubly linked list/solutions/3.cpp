#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <stack>

class Skiplist
{
private:
    //List structured as 2D matrix, with next pointer to right and lower pointer to the same element in the list below
    struct ListNode
    {
        int val;
        ListNode *next, *lower;
        ListNode(int val) : val{val}, next{nullptr}, lower{nullptr}
        {
        }
    };
    // head stores the first (dummy -inf) element of the top most list
    ListNode *head;
    // n is number of nodes , lv is number of levels
    int n, lv;

public:
    Skiplist() : head{new ListNode(0)}, n{0}, lv{1}
    {
        srand(time(0));
    }

    bool search(int target)
    {
        ListNode *node = head;
        while (node)
        {
            // go right till its smaller than search term
            while (node->next && node->next->val < target)
            {
                node = node->next;
            }
            // return true if we find it
            if (node->next && node->next->val == target)
            {
                return true;
            }
            // else go down and search
            node = node->lower;
        }
        return false;
    }

    void add(int num)
    {
        //stack stores the just previous nodes for the new node so that we can insert after them
        std::stack<ListNode *> s;
        ListNode *ptr = head;

        //search for right position and store previous of each level in stack
        while (ptr)
        {
            while (ptr->next && ptr->next->val <= num)
                ptr = ptr->next;
            s.push(ptr);
            ptr = ptr->lower;
        }
        // last is the node for the same value in just lower level to populate lower in new nodes
        ListNode *last = NULL;
        while (!s.empty())
        {
            //previous node in the level
            ptr = s.top();
            s.pop();
            // create new node
            ListNode *node = new ListNode(num);
            node->lower = last;
            //insert node in level
            node->next = ptr->next;
            ptr->next = node;
            last = node;
            // keep going with 50% chance
            if (rand() >= RAND_MAX / 2)
                break;
        }
        n++;
        //if we reached the top level and didn't stop, then create new levels with same idea
        if (s.empty())
        {
            //hard limit number of levels
            int mx = log2(n) + 1;
            while (lv <= mx)
            {
                if (rand() >= RAND_MAX / 2)
                    break;
                //create head for new level
                ListNode *nhead = new ListNode(0);
                nhead->lower = head;
                head = nhead;
                //create node for level and insert after head
                ListNode *node = new ListNode(num);
                node->lower = last;
                last = node;
                nhead->next = node;
                lv++;
            }
        }
    }

    bool erase(int num)
    {
        ListNode *node = head;
        bool ans = false;
        //similar to search but delete node if we find it instead of return
        while (node)
        {
            while (node->next && node->next->val < num)
                node = node->next;
            if (node->next && node->next->val == num)
            {
                node->next = node->next->next;
                ans = true;
            }
            node = node->lower;
        }
        return ans;
    }
};

//---------------------------------
struct Node
{
    int value;
    Node *next = nullptr, *skip = nullptr;
};

Node *readList(const char *name)
{
    std::ifstream is(name);
    if (!is)
    {
        return nullptr;
    }
    int input;
    Node *root, *current;
    is >> input;
    root = new Node{input};
    current = root;
    int size = 1;
    while (is >> input)
    {
        size++;
        current->next = new Node{input};
        current = current->next;
    }

    is.close();
    int k = ceil(sqrt(size));
    current = root;
    Node *prev = root;
    for (size_t i = 1; i < size; i++)
    {
        current = current->next;
        if (i % k == 0)
        {
            prev->skip = current;
            prev = current;
        }
    }

    return root;
}

void print(Node *root)
{
    Node *curr = root;
    while (curr)
    {
        std::cout << "CURRENT: " << curr->value << " WITH SKIP: ";
        if (curr->skip)
        {
            std::cout << curr->skip->value << '\n';
        }
        else
        {
            std::cout << " NO SKIP\n";
        }
        curr = curr->next;
    }
}

bool member(Node *root, int x)
{
    while (root)
    {
#ifdef DEBUG
        std::cout << "CURRENT: " << root->value << "\n";
#endif
        if (root->value == x)
        {
            return true;
        }

        if (root->skip && x > root->skip->value)
        {
            root = root->skip;
        }

        else
        {
            root = root->next;
        }
    }

    return false;
}