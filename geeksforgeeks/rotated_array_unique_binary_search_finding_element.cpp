#include<bits/stdc++.h>
using namespace std;



ifstream yyy("input.txt");
ofstream zzz("output.txt");
typedef long long ll;
int main()
 {
    int test = 0;
    yyy >> test;
    while(test--)
    {
        ll n ;
        yyy >> n;
        vector<ll> array(n);


        for(ll i = 0; i< n;i++)
        {
            // scanf("%lld", &array[i]);
            yyy >> array[i];
        }
        
        ll k; 
        // scanf("%lld", &k);
        yyy >> k;
        ll index = -1;
        
        ll low = 0;
        ll high = n-1;
        ll mid ;
        while(low <= high)
        {
            mid = (low + high)/2;
            
            if(array[mid] == k)
            {
                index = mid;
                break;
            }
            else if( k > array[high] && array[high] >= array[mid] && array[mid] < k )
                high = mid-1;
            else if( k < array[low] && array[low] <= array[mid] && array[mid] > k)
                low = mid + 1;
            else if( k < array[mid])
                high = mid-1;
            else 
                low = mid + 1;
        }
        
        zzz << index;
    
        zzz << endl;
        }
	
	return 0;
}

/* inpt s

3
9
5 6 7 8 9 10 1 2 3
10
3
3 1 2
1
4
3 5 1 2
6

outps
5
1
-1

*/