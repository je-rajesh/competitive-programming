#include <bits/stdc++.h>
using namespace std;

// type definitions
typedef long long ll;

typedef map<int, int> mii;
typedef map<int, int>::iterator miii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef set<int> si;

ifstream yyy("input.txt");
ofstream zzz("output.txt");

// typedef cin yyy;
// typedef cout zzz;

int main()
{
    int test;
    yyy >> test;

    while (test--)
    {
        ll n, k;
        yyy >> n;
        yyy >> k;
        vll array(n);

        for (ll i = 0; i < n; i++)
        {
            yyy >> array[i];
        }


        ll sum = 0;
        ll si = 0, sj = 0;
        ll i;
        // for (i = 0; i < n; i++)
        // {
        //     sum += array[i];
        //     sj = i;
        //     if (sum >= k)
        //     {
        //         break;
        //     }
        // }

        //
        // if (sum == k)
        // {
        //     zzz << si+1 << ' ' << sj+1 << endl;
        //     continue;
        // }

        // while (sum > k)
        // {
        //     sum -= array[si];
        //     si++;
        // }

        // if (sum == k)
        // {
        //     zzz << si+1 << ' ' << sj+1 << endl;
        //     continue;
        // }

        bool flag = false;
        while (sj < n && sum < k)
        {
            sum += array[sj]; 
            if(sum == k)
            {
                flag = true;
                break;
            }
            else if(sum > k) 
            {
                sum -= array[si++];
                if(sum == k)
                {
                    flag = true;
                    break;
                }
            }
            sj++;
        }

        if(flag == false)
        {
            zzz << -1 ;
        }
        else 
            zzz << si+1 << ' ' << sj+1 ;

        zzz << endl;
    }

    return 0;
}
