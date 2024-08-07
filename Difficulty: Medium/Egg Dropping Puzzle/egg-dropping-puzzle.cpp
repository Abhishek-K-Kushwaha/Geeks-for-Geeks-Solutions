//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int f(int n, int k, vector<vector<int>>& dp){
        if (k == 0 || k == 1) return k;
        if (n == 1) return k;
        if (dp[n][k] != -1) return dp[n][k];
        int ans = INT_MAX;
        for (int i = 1; i <= k; i++){
            int brk = 1 + f(n-1, i-1, dp);
            int notbrk = 1 + f(n, k-i, dp);
            //if (i != k) notbrk += f(n, k-i, dp);
            ans = min(ans, max(brk,notbrk));
        }
        return dp[n][k] = ans;
    }
    
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return f(n,k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends