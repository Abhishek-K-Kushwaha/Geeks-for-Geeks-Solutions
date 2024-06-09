//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        for (int i = 0; i <= n; i++){
            dp[1][i] = price[0]*i;
        }
        
        for (int c = 2; c <= n; c++){
            for (int l = 1; l <= n; l++){
                int notcut = dp[c-1][l];
                int cut = 0;
                if (c <= l) cut = price[c-1] + dp[c][l-c];
                dp[c][l] = max(cut, notcut);
            }
        }
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends