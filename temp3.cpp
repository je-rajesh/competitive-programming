#include <bits/stdc++.h>



using namespace std;
typedef long long ll;

// input and output setups
ifstream yyy("input.txt");
ofstream zzz("output.txt");

int main()
{
    ll num, converted_no = 0,ans ;
    int b1, b2, d, power = 0;
    
    yyy >> num >> b1 >> b2; 
    // convert no in base 10 first 
    ll num2 = num;
    while(num2)
    {
        d = num2 % 10;
        converted_no += d*pow(b1, power);
        num2 = num2 / 10;
        power++;
    }
    
    // then convert this into no. of another base.
    power = 1;
    while(converted_no)
    {
        d = converted_no % b2;
        ans += power*d;
        power *= 10;
        converted_no /= b2;
    }
    
    zzz << ans << endl;
}