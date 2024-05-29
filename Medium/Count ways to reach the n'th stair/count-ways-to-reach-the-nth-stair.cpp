//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        const int MOD = 1e9 + 7;
        if (n <= 2)
            return n;
        int prev = 1;
        int ans = 2;
        for (int i = 2; i < n; i++) {
            int nxt = (prev + ans) % MOD;
            prev = ans;
            ans = nxt;
        }
        return ans ;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends