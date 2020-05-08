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
        if (dataAtNode(headref, j) < pivot)
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