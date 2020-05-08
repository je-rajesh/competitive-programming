#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t; 
    cin >> t;

    while(t--)
    {
        int n;
        cin>> n;

        int maxProfit = 0;
        int profit  = 0;
        int temp;


        vector<int>s(n), v(n), p(n);

        for(int i = 0; i< n ;i++)
        {
            cin >> s[i] >> v[i] >> p[i];
            temp = p[i]/s[i] ;
            profit = temp* v[i];

            if(maxProfit < profit)
            {
                maxProfit = profit;
            }
        }

        cout << maxProfit << endl;


        
    }
}