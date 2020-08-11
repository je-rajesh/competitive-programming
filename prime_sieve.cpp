#include <iostream>
void prime_sieve(int *);
#define ll long long
using namespace std;
main()
{
    int n;
    cin >> n;
    int p[1000] = {0};
    prime_sieve(p);
    // print prime no
    for (int i = 0; i <= n; i++)
    {
        if (p[i] == 1)
        {
            cout << i << " ";
        }
    }
}

void prime_sieve(int *p)
{
    // all odd no. as prime
    for (ll i = 3; i < 1000; i += 2)
    {
        p[i] = 1;
    }
    //sieve
    for (ll i = 3; i <= 1000; i += 2) // jumping over odd nos.
    {
        if (p[i] == 1)
        {
            for (ll j = i * i; j <= 1000; j += i)
            {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
}