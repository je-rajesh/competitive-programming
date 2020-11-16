#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, temp;
    
    cin >> n;

    int x = n;

    int sum = 0;

    while (n)
    {
        temp = n % 10;

        sum += pow(temp, 4);

        n = n / 10;   
    }

    if(sum == x){
        cout << "yes" ;
    } else {
        cout << "no";
    }

    cout << endl;
}
