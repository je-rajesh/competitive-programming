/*
    remove the loop from the linked list using floydd method

    one way to find loop is to put temp->next in the set1 and finding address present in the set or not
    unordered_set<Node*>set1
*/



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *insert(Node *head, int data)
{
    if (head == NULL)
        head = new Node(data);
    else
        head->next = insert(head->next, data);
    return head;
}

void makeLoop(Node *head, int x)
{
    if (x == 0)
        return;
    Node *curr = head;
    Node *last = head;

    int counter = 0;
    while (counter < x)
    {
        curr = curr->next;
        counter++;
    }

    while (last->next != NULL)
        last = last->next;
    last->next = curr;
}

int detectloop(Node *head)
{
    Node *hare = head->next;
    Node *tortoise = head;
    while (hare != tortoise && hare != NULL && tortoise != NULL)
    {
        hare = hare->next;
        tortoise = tortoise->next;
        if (hare != NULL && hare->next != NULL)
            hare = hare->next;

        if (hare == tortoise)
            return 1;
    }

    if (hare == tortoise)
        return 1;
    return 0;
}

int length(Node *head, bool hasloop)
{
    int len = 0;
    if (hasloop == false)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        return len;
    }

    else
    {
        Node *hare = head->next;
        Node *tortoise = head;
        while (hare != tortoise)
        {
            hare = hare->next;
            tortoise = tortoise->next;
            hare = hare->next;

            if (hare == tortoise)
                break;
        }

        int looplen = 0;
        while (hare->next != tortoise)
        {
            hare = hare->next;
            looplen++;
        }

        looplen++;

        Node *begin = head;
        int startlen = 0;
        tortoise = tortoise->next;
        while (begin != tortoise)
        {

            begin = begin->next;
            tortoise = tortoise->next;
            startlen++;
        }

        return looplen + startlen;
    }
}

// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
    Node *hare = head;
    Node *turtle = head;
    bool flag = true;

    while (turtle && hare && hare->next && flag)
    {
        turtle = turtle->next;
        hare = hare->next->next;

        if (turtle == hare)
        {
            Node *ptr1 = head;
            Node *ptr2 = hare;

            while (flag)
            {
                ptr2 = hare;
                while (ptr2->next != hare && ptr2->next != ptr1)
                    ptr2 = ptr2->next;

                if (ptr2->next == ptr1)
                {
                    ptr2->next = NULL;
                    flag = false;
                    break;
                }

                ptr1 = ptr1->next;
            }
        }
    }
}

// { Driver Code Starts.

int main()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        Node *head = NULL;
        int sizeOfArray;
        cin >> sizeOfArray;
        int arr[sizeOfArray];
        for (int i = 0; i < sizeOfArray; i++)
        {
            cin >> arr[i];
            head = insert(head, arr[i]);
        }

        int x;
        cin >> x;
        makeLoop(head, x);
        int lengthll = 0;
        if (detectloop(head) == 1)
            lengthll = length(head, true);
        else
            lengthll = length(head, false);

        removeTheLoop(head);

        if (detectloop(head) == 0 && lengthll == length(head, false))
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }
    return 0;
} // } Driver Code Ends