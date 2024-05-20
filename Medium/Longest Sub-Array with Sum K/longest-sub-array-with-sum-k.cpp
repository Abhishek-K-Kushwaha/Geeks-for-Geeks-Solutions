//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int arr[],  int N, int K) 
    { 
        map<int,int> dict;
        int len = 0;
        int pre_sum = 0;
        for (int i = 0; i < N; i++){
            pre_sum += arr[i];
            if (pre_sum == K){
                len =  max(len, i+1);
            }
            
            else if (dict.find(pre_sum - K) != dict.end()){
                len = max(len, i - dict[pre_sum - K]);
            }
            if (dict.find(pre_sum) == dict.end()) dict[pre_sum] = i;
        }
        return len;
    } 
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends