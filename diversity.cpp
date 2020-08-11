#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int test = 0;
    // cin >> test;
    int n, k;
    cin >> n >> k;

    string str = "abcdefghijklmnopqrstuvwxyz";
    string alphabet;

    while(alphabet.size() < n){
        alphabet += str;
    }

    string k_string = alphabet.substr(0, k);
    sort(k_string.begin(), k_string.end());
    string result;


    int multiplier = n / k;

    for (int i = 0; i < multiplier; i++)
        result += k_string;

    cout << result << endl;

    return 0;
}
