// { Driver Code Starts
#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

ifstream yyy("input.txt");
ofstream zzz("output.txt");

/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node **head_ref, int new_data)
{
    /* allocate node */
    struct node *new_node = new node(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        // printf("%d ", node->data);
        zzz << node->data << " ";
        node = node->next;
    }
    // printf("\n");
    zzz << "\n";
}
void quickSort(struct node **headRef);
int main()
{
    int t, n, x;
    yyy >> t;
    while (t--)
    {

        yyy >> n;
        n = n - 1;
        yyy >> x;
        node *temp, *head = new node(x);
        temp = head;
        while (n--)
        {
            yyy >> x;
            temp->next = new node(x);
            temp = temp->next;
        }

        quickSort(&head);

        printList(head);
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    return 0;
} // } Driver Code Ends

/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
void swap(node **headref, int i, int j)
{
    node *temp1 = *headref;
    for (int k = 0; k < i; k++)
        temp1 = temp1->next;

    node *temp2 = *headref;

    for (int k = 0; k < j; k++)
        temp2 = temp2->next;

    int temp = temp1->data;
    temp1->data = temp2->data;
    temp2->data = temp;
}

int dataAtNode(node **headref, int j)
{
    node *temp = *headref;
    for (int i = 0; i < j; i++)
        temp = temp->next;

    return temp->data;
}

int partition(node **headref, int low, int high)
{
    node *temp = *headref;

    for (int i = 0; i < high; i++)
        temp = temp->next;

    int pivot = temp->data;
    int i = low;

    for (int j = low; j < high; j++)
    {
        if (dataAtNode(headref, j) > pivot)
        {
            swap(headref, i, j);
            i++;
        }
    }

    swap(headref, i, high);
    return i;
}

void qsort(node **headref, int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(headref, low, high);

        qsort(headref, low, pi - 1);
        qsort(headref, pi + 1, high);
    }
}

void quickSort(struct node **headRef)
{

    int low = 0;
    int high = 0;

    node *temp = *headRef;
    while (temp != NULL)
    {
        temp = temp->next;
        high++;
    }

    high--;

    qsort(headRef, low, high);
}