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

// input and output setups
ifstream yyy("input.txt");
ofstream zzz("output.txt");

int main()
{
    int test = 0;
    yyy >> test;
    while(test--)
    {
        int n, temp; 
        yyy >> n;
        vi array(n);
        
        for(int i = 0; i< n; i++)
        {
            yyy >> array[i];
        }
        
        /* 
                YOUR CODE HERE 
        */
        for(int i = 0; i< n; i++)
        {
            zzz << array[i]<< ' ';
        }
        zzz << endl;
    
	return 0;
}
