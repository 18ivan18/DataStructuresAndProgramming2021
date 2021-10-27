
//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode *merge(ListNode *left, ListNode *right)
{
    ListNode *result = new ListNode(), *curr = result;
    while (left && right)
    {
        if (left->val > right->val)
        {
            curr->next = right;
            right = right->next;
        }
        else
        {
            curr->next = left;
            left = left->next;
        }
        curr = curr->next;
    }
    while (left)
    {
        curr->next = left;
        left = left->next;
        curr = curr->next;
    }
    while (right)
    {
        curr->next = right;
        curr = curr->next;
        right = right->next;
    }
    return result->next;
}

// Top Down Merge Sort
// Time: O(nlogn)
// Space: O(logn), where n is the number of nodes in linked list.
// Since the problem is recursive, we need additional space to store the recursive call stack.
// The maximum depth of the recursion tree is logn
ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
    {
        return head;
    }
    ListNode *fast = head, *slow = head, *temp = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
    }
    temp->next = nullptr;
    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);
    return merge(left, right);
}

// Bottom Up Merge Sort
// Time: O(nlogn)
// Space: O(1) We use only constant space for storing the reference pointers tail, nextSubList
class Solution
{
public:
    ListNode *tail = new ListNode();
    ListNode *nextSubList = new ListNode();

    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        int n = getCount(head);
        ListNode *start = head;
        ListNode dummyHead(0);
        for (int size = 1; size < n; size = size * 2)
        {
            tail = &dummyHead;
            while (start)
            {
                if (!start->next)
                {
                    tail->next = start;
                    break;
                }
                ListNode *mid = split(start, size);
                merge(start, mid);
                start = nextSubList;
            }
            start = dummyHead.next;
        }
        return dummyHead.next;
    }

    ListNode *split(ListNode *start, int size)
    {
        ListNode *midPrev = start;
        ListNode *end = start->next;
        //use fast and slow approach to find middle and end of second linked list
        for (int index = 1; index < size && (midPrev->next || end->next); index++)
        {
            if (end->next)
            {
                end = (end->next->next) ? end->next->next : end->next;
            }
            if (midPrev->next)
            {
                midPrev = midPrev->next;
            }
        }
        ListNode *mid = midPrev->next;
        nextSubList = end->next;
        midPrev->next = nullptr;
        end->next = nullptr;
        // return the start of second linked list
        return mid;
    }

    void merge(ListNode *list1, ListNode *list2)
    {
        ListNode dummyHead(0);
        ListNode *newTail = &dummyHead;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                newTail->next = list1;
                list1 = list1->next;
                newTail = newTail->next;
            }
            else
            {
                newTail->next = list2;
                list2 = list2->next;
                newTail = newTail->next;
            }
        }
        newTail->next = (list1) ? list1 : list2;
        // traverse till the end of merged list to get the newTail
        while (newTail->next)
        {
            newTail = newTail->next;
        }
        // link the old tail with the head of merged list
        tail->next = dummyHead.next;
        // update the old tail with the new tail of merged list
        tail = newTail;
    }

    int getCount(ListNode *head)
    {
        int cnt = 0;
        ListNode *ptr = head;
        while (ptr)
        {
            ptr = ptr->next;
            cnt++;
        }
        return cnt;
    }
};
