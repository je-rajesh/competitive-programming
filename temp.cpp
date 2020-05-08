// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

ifstream yyy("input.txt");
ofstream zzz("output.txt");
 // } Driver Code Ends


    void max_of_subarrays(int *arr, int n, int k){
        int totalIteration = n - k + 1;
        vector<int>array;
        stack<int>auxStack;
        stack<int>mainStack;

        

        for(int i = 0; i< array.size(); i++)
        {
            zzz << array[i] << ' ';
        }
 
    }


// { Driver Code Starts.

int main() {
	
	int t;
	yyy >> t;
	
	while(t--){
	    
	    int n, k;
	    yyy >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        yyy >> arr[i];
	    
	    max_of_subarrays(arr, n, k);
	    zzz << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends