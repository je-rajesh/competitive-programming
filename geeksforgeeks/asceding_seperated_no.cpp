#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream inp("input.txt");
ofstream oup("output.txt");

bool compareFunction(int a, int b)
{
    if(a > 0 && b > 0 && a<b)
        return true;
    else if( a > 0 && b < 0 )
        return true;
    else if( b > 0 && a < 0)
        return false;
    else if( a< 0 && b < 0 && a<b)
        return true;
    else return false;
}


int main()
 {
    int test = 0;
    inp >> test;
    while(test--)
    {
        int n; 
 

        inp >> n;
        vector<int>array(n);
        
        for(int i = 0; i< n; i++)
        {
            inp >> array[i];
        }
        
        stable_sort(array.begin(), array.end(), compareFunction);
        
        for(int i = 0; i< n; i++)
        {
            oup << array[i]<< ' ';
        }
        oup << endl;
    }
	
	return 0;
}