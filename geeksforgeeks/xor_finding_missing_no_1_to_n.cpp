/*
    find the mising no. into 1..... n;
    just one missing.

    one method
     int i, total=1;  
      
    for ( i = 2; i<= (n+1); i++) 
    { 
        total+=i; 
        total -= a[i-2]; 
    } 
    return total; 

    another method:
    sum = n*(n+1)/2;
    sum - sumOfAllElements;

*/


#include <bits/stdc++.h>
using namespace std;

// type definitions
typedef long long ll;

typedef map<int, int> mii;
typedef map<int, int>::iterator miii;
typedef vector<int> vi;
typedef vector<ll>vll;
typedef pair<int, int> pii;
typedef set<int> si;

ifstream yyy("input.txt");
ofstream zzz("output.txt");

int main()
{
    int test;
    yyy >> test;

    while (test--)
    {
        ll n;
        yyy >> n;
        vll array(n);

        for(ll i = 0; i< n-1 ; i++)
        {
            yyy >> array[i];
        }

        ll a = array[0];
        
        for(ll i = 1; i < n-1; i++)
        {
            a = a^array[i];
        }
        ll b = 1;
        for(ll i = 2;i<=n;i++)
        {
            b = b^i;
        }

        ll temp = a^b;
        zzz << temp << endl;
    }

    return 0;
}

