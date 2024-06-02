//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(3, 0));
    
    for (int i = 0; i < 3; i++) {
        dp[0][i] = points[0][i];
    }
    
    for (int day = 1; day < n; day++) {
        for (int i = 0; i < 3; i++) {
            dp[day][i] = max(
                points[day][i] + dp[day - 1][(i + 1) % 3], 
                points[day][i] + dp[day - 1][(i + 2) % 3]
            );
        }
    }
    
    int maxsum = max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    return maxsum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
