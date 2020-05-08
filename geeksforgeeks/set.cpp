#include <bits/stdc++.h>
using namespace std;

// type definitions
typedef map<int, int> mii;
typedef map<int, int>::iterator miii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef set<int> si;

ifstream yyy("input.txt");
ofstream zzz("output.txt");

int main()
{
    int test;
    yyy >> test;

    while (test--)
    {
        int n;
        yyy >> n;
        int temp;
        si s;
        for(int i = 0;i< n; i++)
        {
            yyy >> temp;

            if(s.find(temp)!= s.end())
            {
                s.erase(temp);
            }
            else
            {
                s.insert(temp);
            }
        }

        zzz << *(s.begin());

       
        zzz << endl;
    }

    return 0;
}
