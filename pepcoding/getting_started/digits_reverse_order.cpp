#include <bits/stdc++.h>
using namespace std;

// type definitions
typedef long long ll;

ifstream yyy("input.txt");
ofstream zzz("output.txt");

int main()
{
    ll num = 0; 
    yyy >> num;

    while(num)
    {
        zzz << num % 10 << endl;
        num = num / 10;
    }
	return 0;
}
