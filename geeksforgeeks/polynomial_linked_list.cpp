// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

ifstream yyy("input.txt");
ofstream zzz("output.txt");


/* Link list Node */
struct Node
{
    int coeff;
    int pow;
    struct Node *next;

    Node(int c, int p)
    {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

void append(struct Node **head_ref, struct Node **tail_ref,
            int new_data, int new_data1)
{
    struct Node *new_Node = new Node(new_data, new_data1);

    if (*head_ref == NULL)
        *head_ref = new_Node;
    else
        (*tail_ref)->next = new_Node;
    *tail_ref = new_Node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d %d ", temp->coeff, temp->pow);
        temp = temp->next;
    }
}

void swap(Node **headref, int i, int j);

void addPolynomial(Node *p1, Node *p2);

void create_Node(int x, int y, struct Node **temp)
{
    struct Node *r, *z;
    z = *temp;
    if (z == NULL)
    {
        r = new Node(x, y);
        *temp = r;
        r->next = NULL;
    }
    else
    {
        r->next = new Node(x, y);
        r = r->next;
        r->next = NULL;
    }
}

/* Driver program to test above function*/
int main()
{

    int t;
    yyy >> t;
    while (t--)
    {
        struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
        struct Node *tail1 = NULL, *tail2 = NULL;
        int n;
        yyy >> n;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            yyy >> x >> y;
            append(&poly1, &tail1, x, y);
        }

        int m;
        yyy >> m;
        for (int i = 0; i < m; i++)
        {
            int x, y;
            yyy >> x >> y;
            append(&poly2, &tail2, x, y);
        }

        addPolynomial(poly1, poly2);

        zzz << endl;
    }
}

void printHead(Node* head)
{
    Node* temp = head;

    while(temp->next)
    {
        zzz << temp->coeff << "x^" << temp->pow << "+";
        temp = temp->next;
    }

    zzz << temp->coeff << "x^" << temp->pow << endl;
}



void swap(Node **headref, int i, int j)
{
    Node *temp1 = *headref;
    for (int k = 0; k < i; k++)
        temp1 = temp1->next;

    Node *temp2 = *headref;

    for (int k = 0; k < j; k++)
        temp2 = temp2->next;

    int temp = temp1->coeff;
    temp1->coeff = temp2->coeff;
    temp2->coeff = temp;

    temp = temp1->pow;
    temp1->pow = temp2->pow;
    temp2->pow = temp;
}

int dataAtNode(Node **headref, int j)
{
    Node *temp = *headref;
    for (int i = 0; i < j; i++)
        temp = temp->next;

    return temp->pow;
}

int partition(Node **headref, int low, int high)
{
    Node *temp = *headref;

    for (int i = 0; i < high; i++)
        temp = temp->next;

    int pivot = temp->pow;
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

void qsort(Node **headref, int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = partition(headref, low, high);

        qsort(headref, low, pi - 1);
        qsort(headref, pi + 1, high);
    }
}

void quickSort(struct Node **headRef)
{

    int low = 0;
    int high = 0;

    Node *temp = *headRef;
    while (temp != NULL)
    {
        temp = temp->next;
        high++;
    }

    high--;

    qsort(headRef, low, high);
}

void addPolynomial(Node *p1, Node *p2)
{
    quickSort(&p1);
    quickSort(&p2);

    Node *head = NULL;
    Node *var = NULL;
    Node *temp1 = p1;
    Node *temp2 = p2;
    Node *prev = NULL;

    if (temp1->pow > temp2->pow)
    {
        head = new Node(temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }
    else if (temp1->pow < temp2->pow)
    {
        head = new Node(temp2->coeff, temp2->pow);
        temp2 = temp2->next;
    }
    else
    {
        head = new Node (temp1->coeff + temp2->coeff, temp1->pow);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    prev = head;

    while (temp1 && temp2)
    {
        if (temp1->pow > temp2->pow)
        {
            var = new Node(temp1->coeff, temp1->pow);
            temp1 = temp1->next;
            prev->next = var;
            prev = var;
        }
        else if (temp1->pow < temp2->pow)
        {
            var = new Node(temp2->coeff, temp2->pow);
            temp2 = temp2->next;
            prev->next = var;
            prev = var;
        }
        else
        {
            var = new Node(temp1->coeff + temp2->coeff, temp1->pow);
            temp1 = temp1->next;
            temp2 = temp2->next;
            prev->next = var;
            prev = var;
        }
    }

    while(temp1)
    {
        var = new Node(temp1->coeff, temp1->pow);
        prev->next = var;
        temp1 = temp1->next;
        prev = var;
    }

    while(temp2)
    {
        var = new Node(temp2->coeff, temp2->pow);
        prev->next = var;
        prev = var;
        temp2 = temp2->next;
    }

    printHead(head);

 
}
