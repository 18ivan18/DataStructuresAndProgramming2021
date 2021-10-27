#include <stack>
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head)
{
    std::stack<ListNode *> st;
    while (head)
    {
        st.push(head);
        head = head->next;
    }
    ListNode *dummyHead = new ListNode(), *curr = dummyHead;
    while (!st.empty())
    {
        curr->next = st.top();
        st.pop();
        curr = curr->next;
    }
    curr->next = nullptr;
    return dummyHead->next;
}

// 1 2 3 4 5
/*
        {
            head = 1
            temp = {
                head = 2
                temp = {
                    head = 3
                    temp = 5->4 
                    {
                        head = 4
                        temp = 5 {
                            head = 5
                            return 5
                        }
                        5->next = 4
                        4->next = nullptr
                        return 5
                    }
                    5->4->next = 3
                    3->next = nullptr
                    return 3
                }
            }
        }
    */
ListNode *reverseListRec(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *temp = reverseListRec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
}
