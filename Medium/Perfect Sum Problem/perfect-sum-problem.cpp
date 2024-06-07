//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>> dp(n, vector<int>(sum+1,0));
        
        for (int t = 0; t <= sum; t++){
            if (t == 0 && arr[0] == 0) dp[0][t] = 2;
            else if (t == 0 || arr[0] == t) dp[0][t] = 1;
        }
        for (int i = 1; i < n; i++){
            for (int t = 0; t <= sum; t++){
                int notpick = dp[i-1][t];
                int pick = 0;
                if (arr[i] <= t) pick = dp[i-1][t-arr[i]];
                dp[i][t] = (pick + notpick) % 1000000007;
            }
        }
        return dp[n-1][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends