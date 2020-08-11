#include<iostream>
#include<cmath>

using namespace std;
typedef long long ll;

int main()
{
    ll low = 0, high = 0;
    
    cin >> low >> high;
    
    for(ll n = low ; n<= high; n++)
    {
        bool flag = true;
        ll num = ceil(sqrt(n));
        for(ll i = 2; i <=num ; i++)
        {
            if(n % i == 0 && n != i)
            {
                flag = false;
                break;
            }
        }
        
        if(flag == true)
        {
            cout << n << endl;
        }
    }
}


