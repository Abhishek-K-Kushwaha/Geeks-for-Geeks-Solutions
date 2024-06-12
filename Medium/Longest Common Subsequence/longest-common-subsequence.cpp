//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int len1, int len2, string text1, string text2) {
        // int len1 = text1.size();
        // int len2 = text2.size();
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        int flag = 0;
        for (int i = 0; i < len2; i++) {
            if (flag || text1[0] == text2[i]) {
                dp[0][i] = 1;
                flag = 1;
            }
        }
        flag = 0;
        for (int i = 0; i < len1; i++) {
            if (flag || text2[0] == text1[i]) {
                dp[i][0] = 1;
                flag = 1;
            }
        }
        for (int ind1 = 1; ind1 < len1; ind1++) {
            for (int ind2 = 1; ind2 < len2; ind2++) {
                if (text1[ind1] == text2[ind2])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else {
                    dp[ind1][ind2] =
                        0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
                }
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends