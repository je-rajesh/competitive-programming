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
typedef map<char, int> mci;
// input and output setups
ifstream yyy("input.txt");
ofstream zzz("output.txt");

class Solution
{
public:
    int firstUniqChar(string s)
    {
        mci unique;

        for (int i = 0; i < s.size(); i++)
        {
            unique[s[i]]++;
        }

        int c = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (unique[s[i]] == 1)
            {   c = i;
                break;
            }
        }
        return c;
    }

};

int main()
{
    int test = 0;
    yyy >> test;
    while (test--)
    {
        int n, temp;

        string array;

        cin >> array;

        Solution sol;

        int ans = sol.firstUniqChar(array);
        zzz << ans << endl;

        return 0;
    }
}
