//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimizeCost(vector<int>& h, int n, int k) {
        vector<int> dp(n+1, -1);
        int mincost = 0;
        dp[1] = mincost;
        for (int i = 2; i <= n; i++){
            //dp[i] = mincost;
            mincost = INT_MAX;
            for (int j = 1; j <= k; j++){
                if (i-j > 0 ){
                    int temp = dp[i-j] + abs(h[i-1] - h[i-j-1]);
                    mincost = min(mincost, temp);
                }
            }
            dp[i] = mincost;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends