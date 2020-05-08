#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    int test = 0;
    cin >> test;
    while (test--)
    {
        // my code here;

        LL n;
        scanf("%lld", &n);
        vector<int> array(n);

        for (LL i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }

        int leader = array[n - 1];
        stack<int> result;
        result.push(leader);
        for (LL i = n - 2; i >= 0; i--)
        {
            if (array[i] >= leader)
            {
                leader = array[i];
                result.push(leader);
            }
        }
        n = result.size();
        for(LL i = 0; i < n; i++)
        {
            printf("%d ", result.top());
            result.pop();
        }

        printf("\n");
    }

    return 0;
}