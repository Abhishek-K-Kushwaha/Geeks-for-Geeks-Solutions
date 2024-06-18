//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        vector<int> dp(n, 1);
        vector<int> hash(n);
        for (int ind = 0; ind < n; ind++) {
            hash[ind] = ind;
            for (int prev = 0; prev < ind; prev++) {
                if (nums[ind] > nums[prev] && dp[ind] < 1 + dp[prev]) {
                    dp[ind] = 1 + dp[prev];
                    hash[ind] = prev;
                    
                } 
            }
        }
        int maxind = 0; 
        for (int i = 0; i < n; i++){
            if (dp[i] > dp[maxind]){
                maxind = i;
            }
        }
        vector<int> ans;
        while (true){
            ans.push_back(nums[maxind]);
            if (maxind == hash[maxind]) break;
            maxind = hash[maxind];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends