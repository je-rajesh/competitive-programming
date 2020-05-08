/*
this algorithm (quickselect methd) uses median approach 
O(n) in it.

otherwise O(n) with worst time O(n^2)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int partition(vector<int> &array, int l, int r, int pivot)
{
    // int pivot = array[r];
    int j = l;
    for (int i = l; i < r; i++)
    {
        if (array[i] <= pivot)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            j++;
        }
    }
    int temp = array[r];
    array[r] = array[j];
    array[j] = temp;

    return j;
}

int findMedian(vector<int>::iterator ptr, int n)
{
    vector<int>::iterator end = ptr + 5;
    sort(ptr, end);
    return *(ptr + n / 2);
}

int kThSmallest(vector<int> &array, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;

        int i;
        vector<int> median((n + 4) / 5);

        for (i = 0; i < n / 5; i++)
        {
            median[i] = findMedian(array.begin() + l + i * 5, 5);
        }

        if (i * 5 < n)
        {
            median[i] = findMedian(array.begin() + l + i * 5, n % 5);
            i++;
        }

        int medMedian = (i == 1) ? (median[i - 1]) : kThSmallest(median, 0, i - 1, i / 2);

        int pos = partition(array, l, r, medMedian);

        if (pos - l == k - 1)
            return array[pos];

        else if (pos - l > k - 1)
            return kThSmallest(array, l, pos - 1, k);
        else
            return kThSmallest(array, pos + 1, r, k + l - pos - 1);
    }

    return 0;
}

int main()
{
    ifstream inp("input.txt");
    ofstream oup("output.txt");



    int test = 0;
    inp >> test;
    while (test--)
    {
        int n;
        inp >> n;
        vector<int> array(n);
        int temp;
        for (int i = 0; i < n; i++)
        {
            inp >> array[i];
        }

        // cout << array.size();

        int k;
        inp >> k;
        int result = kThSmallest(array, 0, n - 1, k);

        oup << result << endl;
        // printf("\n");
    }

    return 0;
}