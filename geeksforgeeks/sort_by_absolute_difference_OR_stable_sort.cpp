/*
    explanation: sort by absolute difference.
    concepts used: stable_sort with compartfunction which uses an global varaible
*/


#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int k;
bool compareFunction(int a, int b)
{
    if(abs(a-k) < abs(b-k)) return 1 ;
    else return 0;
}

int main()
 {
    int test = 0;
    cin >> test;
    while(test--)
    {
        int n;
        cin >> n >> k;
        
        vector<int>array(n);
        vector<int>temp(n);
        
        for(int i = 0 ;i < n ;i++)
        {
            temp[i] = abs(array[i] - k);
        }
        
        for(int i = 0 ;i < n ;i++)
        {
            cin >> array[i];
        }
    
    stable_sort(array.begin(), array.end(), compareFunction);
    
    for(int i = 0 ;i < n ;i++)
    {
         cout << array[i]<< ' ';
    }
    printf("\n");
    }
	
	return 0;
}