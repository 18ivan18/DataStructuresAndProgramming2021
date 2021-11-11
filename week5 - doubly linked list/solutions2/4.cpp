#include <vector>

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode *head)
{
    std::vector<ListNode *> nodes;
    ListNode *cur = head;
    while (cur)
    {
        nodes.push_back(cur);
        cur = cur->next;
    }

    int left = 0;
    int right = nodes.size() - 1;
    while (right - left > 1)
    {
        nodes[left]->next = nodes[right];
        nodes[right]->next = nodes[left + 1];
        ++left;
        --right;
    }
    if (right > 0)
    {
        nodes[right]->next = nullptr;
    }
}

ListNode *reverseList(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *nextptr;

    while (curr)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;
    }
    return prev;
}

void reorderList(ListNode *head)
{

    ListNode *slow = head;
    ListNode *fast = head->next;
    ListNode *mid = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        mid = mid->next;
    }
    slow = slow->next;
    mid->next = nullptr;

    slow = reverseList(slow);

    fast = head;

    while (slow != nullptr)
    {
        ListNode *firstHalfNext = fast->next;
        ListNode *secondHalfNext = slow->next;
        fast->next = slow;
        fast = firstHalfNext;
        slow->next = firstHalfNext;
        slow = secondHalfNext;
    }
}