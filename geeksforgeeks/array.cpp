#include<iostream>
#include<vector>
typedef long long LL;
using namespace std;
int main()
 {
    int test = 0;
    cin >> test;
    while(test-- ){
    // my code here;
    
    
    LL N, i, newIndex ;
    scanf("%lld", &N);
    int D;
    scanf("%d", &D);
    
    
    vector<int>array(N+10);
    
    
    for( i = 0; i< N; i++)
    {
        newIndex = (i  - D + N)%N;
        scanf("%d", &array[newIndex]);
    }
    
    for( i = 0 ; i < N; i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
    
    
    }
	
	return 0;
}