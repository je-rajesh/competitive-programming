#include <bits/stdc++.h>
using namespace std;

//All Typedef's are here.
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef set<int> si;
typedef set<ll> sll;
typedef vi::iterator viI;
typedef sll::iterator sllI;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef map<int, int> mii;
// typedef vector<vector<int>&> vvi;

//input file and outfile
ifstream yyy("input.txt");
ofstream zzz("output.txt");

void get_next_position(int x, int y, int direction, pii& ans)
{
    if (direction == 0)
    {
        ans.first = x;
        ans.second = y + 1;
    }
    else if (direction == 1)
    {
        ans.first = x + 1;
        ans.second = y;
    }
    else if (direction == 2)
    {
        ans.first = x;
        ans.second = y - 1;
    }
    else
    {
        ans.first = x - 1;
        ans.second = y;
    }

}

int main()
{
    int n, m;

    yyy >> n >> m;
    // vvi array;
    vector<vector<int>>array(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            yyy >> array[i][j];
        }
    }

    int entry_x = 0, entry_y = 0;

    bool flag = false;
    int check_x, check_y;
    int direction = 0;
    int temp_x ; 
    int temp_y ;

    while (!flag)
    {
        // looking in the east direction first.
        pii pos;
        get_next_position(entry_x, entry_y, direction, pos);

        temp_x = pos.first;
        temp_y = pos.second;

        if(temp_x < 0 || temp_x >= n || temp_y < 0 || temp_y >= m)
        {
            zzz << entry_x << entry_y;
            exit(0);
        }
        

        if(array[temp_x][temp_y] == 1)
        {
            direction = (direction+1)%4;
        }

        entry_x = temp_x;
        entry_y = temp_y;
    }
}
