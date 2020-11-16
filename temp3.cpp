#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
typedef long long ll;

ifstream yyy("input.txt");
ofstream zzz("output.txt");

int main()
{
    int n1, m1;
    yyy >> n1 >> m1;

    vector<vector<ll>>array1(n1, vector<ll>(m1));

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m1; j++)
            yyy >> array1[i][j];
    }
    
    int n2, m2; 
    yyy >> n2 >> m2;

    vector<vector<ll>>array2(n2, vector<ll>(m2));

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < m2; j++)
            yyy >> array2[i][j];
    }
    
    // multipliing two matrices. 
    if(n2 != m1){
        zzz << "Invalid input" << endl;
        return 0;
    } 
    
    vector<vector<ll>>array3(n1, vector<ll>(m2));
    
    int sum = 0;
    
    for(int i = 0; i< n1; i++)
    { 
        for(int j = 0; j< m2; j++)
        {
            sum = 0;
            for(int k = 0; k < m1; k++)
            {
                sum += array1[n1][k] * array2[k][m2];
            }
            
            array3[i][j] = sum;
        }
        
    }
    
    for(int i=0 ; i< n1; i++)
    {
        for(int j= 0; j < m2; j++)
        {
            zzz << array3[i][j] << " ";
        }
        
        zzz << endl;
    }
}