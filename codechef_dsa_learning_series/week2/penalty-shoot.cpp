#include <iostream>
#include <string>

using namespace std;
int main()
{
    int t;

    cin >> t;
    while (t--)
    {
        int n;
        int total = 2 * n;
        int aScore = 0;
        int bScore = 0;
        int totalCount = 2 * n;
        int diff = 0;
        int left = 0;
        int turn = 0;
        string arr;
        cin >> arr;
        total = arr.size();
        n = total / 2;

        for (int i = 0; i < total; i++)
        {
            if (arr[i] == '1')
            {
                if (i & 1)
                {
                    bScore++;
                }
                else
                {
                    aScore++;
                }
            }

            if (aScore > bScore)
            {
                diff = aScore - bScore;
                turn = (i / 2)  + 1;
                left = n - turn;

                if (diff > left)
                {
                    cout << i + 1;
                }
            }
            else if (bScore > aScore)
            {
                diff = bScore - aScore;
                turn = i / 2;
                left = n - turn;

                if (diff > left)
                {
                    cout << i + 1;
                }
            }
        }
    }
}
