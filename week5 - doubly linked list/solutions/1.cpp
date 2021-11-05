// FIXME: doen't work
class MyCircularDeque
{
    struct Node
    {
        Node *prev, *next;
        int val;
        Node(int x) : val{x}, prev{nullptr}, next{nullptr}
        {
        }
    };

    Node *getTail()
    {
        return head->prev;
    }

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    Node *head;
    int curSize, maxSize;
    MyCircularDeque(int k) : maxSize{k}, head{nullptr}, curSize{0}
    {
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value)
    {
        if (curSize >= maxSize)
        {
            return false;
        }
        head->next = head;

        Node *toBeInserted = new Node(value);
        if (curSize == 0)
        {
            head = toBeInserted;
            head->prev = head;
            curSize++;
            return true;
        }

        toBeInserted->next = head;
        getTail()->next = toBeInserted;
        toBeInserted->prev = getTail();
        head->prev = toBeInserted;
        head = toBeInserted;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value)
    {
        if (curSize >= maxSize)
        {
            return false;
        }

        curSize++;
        Node *toBeInserted = new Node(value);

        if (curSize == 0)
        {
            head = toBeInserted;
            head->prev = head;
            head->next = head;
            return true;
        }
        Node *tail = getTail();
        tail->next = toBeInserted;
        toBeInserted->next = head;
        head->prev = toBeInserted;
        toBeInserted->prev = tail;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront()
    {
        if (isEmpty())
        {
            return false;
        }
        Node *toBeDeleted = head, *tail = getTail();
        head = head->next;
        tail->next = head;
        head->prev = tail;
        curSize--;
        delete toBeDeleted;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast()
    {
        if (isEmpty())
        {
            return false;
        }
        Node *tail = getTail();
        tail->prev->next = head;
        head->prev = tail;
        curSize--;
        delete tail;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        return head->val;
    }

    /** Get the last item from the deque. */
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return getTail()->val;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty()
    {
        return curSize == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull()
    {
        return curSize == maxSize;
    }
};