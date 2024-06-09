//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int amount) {

        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));
        for (int t = 0; t <= amount; t++) {
            if (t % coins[0] == 0)
                dp[0][t] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                long long notpick = dp[i - 1][t];
                long long pick = 0;
                if (coins[i] <= t)
                    pick = dp[i][t - coins[i]];
                dp[i][t] = pick + notpick;
            }
        }
        return dp[n - 1][amount];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends