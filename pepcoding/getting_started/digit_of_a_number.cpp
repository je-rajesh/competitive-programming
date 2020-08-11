#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// input and output setups
ifstream yyy("input.txt");
ofstream zzz("output.txt");


int main()
{
   ll divisor = 10000000000;
   ll num, temp ;
   yyy >> num;
   
   temp = num;

   while(temp == num)
   {
       divisor /= 10;
       temp %= divisor;
   }
   
   
   while(num)
   {
        int foo = num / divisor;
        zzz << foo << endl;
        num %= divisor;
        divisor /= 10;
   }
   
   
   
}