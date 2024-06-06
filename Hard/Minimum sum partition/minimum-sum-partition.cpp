//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
    	for (int i = 0; i < n; i++){
    		sum += arr[i];
    	}
    	int orgsum = sum;
    	sum /= 2;
    	vector<vector<bool>> dp(n, vector<bool>(sum+1, 0));
    	for (int i = 0; i < n; i++){
    		dp[i][0] = true;
    	}
    	if (arr[0] <= sum) dp[0][arr[0]] = true;
    
    	for (int ind = 1; ind < n; ind++){
    		for (int tar = 1; tar <= sum; tar++){
    			int nottake = dp[ind-1][tar];
    			int take = false;
    			if (arr[ind] <= tar) take = dp[ind-1][tar-arr[ind]];
    			dp[ind][tar] = (take || nottake);
    		}
    	}
    	for (int i = sum; i >= 0; i--){
    		if (dp[n-1][i]) return orgsum - 2*i;
    	}
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends