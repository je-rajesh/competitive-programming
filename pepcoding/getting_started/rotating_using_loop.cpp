#include <bits/stdc++.h>
using namespace std;

// type definitions
typedef long long ll;

ifstream yyy("input.txt");
ofstream zzz("output.txt");

int main()
{
    ll num = 0, k=0;
    yyy >> num;
    yyy >> k;

    // find highest order of the number.
    ll temp = num, count = 0;
    while (temp)
    {
        temp /= 10;
        count++;
    }
    // operation when k >= 0
    if (k >=0)
    {
        // find the no of rotation actually needed.
        k = k % count;

        // finding the second part and first part.
        ll divisor = pow(10, k);
        ll second_part = num / divisor;
        ll first_part = num % divisor;

        first_part = first_part*pow(10, count-k);
        num = first_part + second_part;
    }  // operation when k <= 0
    else
    {
        k = -k;

        // find the no of rotation actually needed.
        k = k % count;

        // finding the first and second part of `num`
        ll divisor = pow(10, count-k);
        ll second_part = num / divisor;
        ll first_part = num % divisor;

        first_part = first_part * pow(10, k);
        num = first_part + second_part ;
    }

    zzz << num;


    return 0;
}
