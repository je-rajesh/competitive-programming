#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
 {
    int test = 0;
    cin >> test;
    while(test--)
    {
        // my code here;
        int n, k;
        scanf("%d%d", &n, &k);
        
        vector<ll>array(n);
        vector<ll>result(n);

        for(int i = 0; i< n;i++)
        {
            scanf("%lld", &array[i]);
        }
        
        int d = floor(n/k);
        int offset = 0;
        
        for(int i = 0; i< d ; i++)
        {
            offset = i*k;
            for(int j=0; j<k; j++)
            {
                result[offset + k - 1 - j] = array[offset + j];
            }
        }
        
        if(n%k != 0)
        {
            offset = d*k;
            int len = n - offset ;
            
            for(int j = 0; j < len; j++)
            {
                result[offset + len -1 -j] = array[offset + j];
            }
        }
        
        for(int i = 0; i < n ;i++)
        {
            printf("%lld ", result[i]);
        }
        
    
    printf("\n");
    }
	
	return 0;
}