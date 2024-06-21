//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string s)
    {
        int n = s.size();
        vector<int> dp(n+1, 0);
        vector<vector<bool>> isPal(n, vector<bool> (n, false));
        for (int i = 0; i < n; i++) {
            isPal[i][i] = true;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len == 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }
        for (int i = n-1; i >= 0; i--){
            int ans = n;
            for (int j = i; j < n; j++){
                if (isPal[i][j]){
                    int cuts = 1 + dp[j+1]; // f(j+1, s, n, dp);
                    ans = min(ans, cuts);
                }
            }
            dp[i] = ans;
        }
        return dp[0] - 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends