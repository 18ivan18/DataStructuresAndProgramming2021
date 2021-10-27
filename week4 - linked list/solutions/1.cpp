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

// Recursive function to reverse a given linked list. It reverses the
// given linked list by fixing the head pointer and then `.next`
// pointers of every node in reverse order
void recursiveReverse(struct ListNode *head, struct ListNode **headRef)
{
    struct ListNode *first;
    struct ListNode *rest;

    // empty list base case
    if (head == NULL)
    {
        return;
    }

    first = head;       // suppose first = {1, 2, 3}
    rest = first->next; // rest = {2, 3}

    // base case: the list has only one node
    if (rest == NULL)
    {
        // fix the head pointer here
        *headRef = first;
        return;
    }

    // recursively reverse the smaller {2, 3} case
    // after: rest = {3, 2}
    recursiveReverse(rest, headRef);

    // put the first item at the end of the list
    rest->next = first;
    first->next = NULL; // (tricky step — make a drawing)
}

// Reverse a given linked list. The function takes a pointer
// (reference) to the head pointer
void reverse(struct ListNode **head)
{
    recursiveReverse(*head, head);
}

void reverse(struct ListNode **head)
{
    struct ListNode *previous = NULL; // the previous pointer
    struct ListNode *current = *head; // the main pointer

    // traverse the list
    while (current != NULL)
    {
        // tricky: note the next node
        struct ListNode *next = current->next;

        current->next = previous; // fix the current node

        // advance the two pointers
        previous = current;
        current = next;
    }

    // fix the head pointer to point to the new front
    *head = previous;
}