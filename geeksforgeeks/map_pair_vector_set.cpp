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
    int t;
    yyy >> t;

    while (t--)
    {
        int n;
        yyy >> n;

        pii p;
        mii map1;
        vi array(n);

        for (int i = 0; i < n; i++)
        {
            yyy >> array[i];
            map1[array[i]]++;
        }

        si s(array.begin(), array.end());
        // vi diff(s.begin(), s.end());


        int result = -1;

        for (miii i = map1.begin(); i != map1.end(); i++)
        {
            if (i->second > n / 2)
                result = i->first;
        }

        zzz << result << endl;
    }

    return 0;
}

            // if (map1.find(array[i]) == map1.end())
            // {
            //     p = make_pair(array[i], 0);
            //     map1.insert(p);
            // }
            // else
            // {
            //     miii t = map1.find(array[i]);
            //     t->second++;
            // }