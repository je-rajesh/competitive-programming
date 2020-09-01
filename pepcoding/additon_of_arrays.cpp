#include <bits/stdc++.h>



using namespace std;
typedef long long ll;

// input and output setups
ifstream yyy("input.txt");
ofstream zzz("output.txt");

int main()
{
    int n1, n2, max ;
    yyy >> n1; 
    vector<int>array1(n1);

    for(int i=0; i<n1; i++) yyy >> array1[i];
    
    yyy >> n2;
    vector<int>array2(n2);
    
    for(int i=0; i<n2; i++) yyy >> array2[i];
    
    int diff = fabs(n2-n1);
    
    // int max = n1 ? n1 >= n2 : n2 ;

    vector<int> larger, smaller; 
    if(n2 >= n1) {
        max = n2; 
        smaller = array1;
        larger = array2;
    }
    else
    {
        max = n1; 
        smaller = array2; 
        larger = array1;
    }
    

    vector<int>array3(max);
    
    for(int i=max-1; i>=0; i--) {
        if(i-diff >= 0){
            array3[i] = larger[i] + smaller[i - diff];
        }
        else {
            array3[i] = larger[i] ; 
        }
    }
    
    for(int i = 0; i<max; i++) zzz << array3[i] << endl;
}