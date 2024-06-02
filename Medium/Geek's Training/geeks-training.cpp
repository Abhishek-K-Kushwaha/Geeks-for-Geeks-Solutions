//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(vector<vector<int>>& points, int day, int last, vector<vector<int>>& dp){
        int maxsum = 0;
        if (day <= 0){
            for (int i = 0; i < 3; i++){
                if (i != last){
                    maxsum = max(maxsum, points[day][i]);
                }
            }
            dp[day][last] = maxsum;
            return maxsum;
        }
        if (dp[day][last] != -1) return dp[day][last];
        for (int i = 0; i < 3; i++){
            if (i != last){
                maxsum = max(maxsum, points[day][i] + f(points, day-1, i, dp));
            }
        }
        dp[day][last] = maxsum;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int>(3,-1));
        int maxsum = 0;
        for (int i = 0; i < 3; i++){
            maxsum = max(maxsum, points[n-1][i] + f(points, n-2, i, dp));
        }
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