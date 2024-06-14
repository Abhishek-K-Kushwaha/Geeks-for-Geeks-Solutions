//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string p, string s)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        int j = 1;
        while (p[j-1] == '*'){
            dp[0][j] = true;
            j++;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (p[j-1] == '*') {
                    bool notmatch = dp[i][j-1]; 
                    bool match = dp[i-1][j]; 
                    dp[i][j] = (notmatch || match);
                }
                else if (p[j-1] == '?' || s[i-1] == p[j-1])
                    dp[i][j] = dp[i-1][j-1]; 
            }
        }
        return dp[n][m];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends