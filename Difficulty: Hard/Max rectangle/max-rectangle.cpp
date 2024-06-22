//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int largestRectangleInHistogram(vector<int>& heights, int n) {
        //int n = heights.size();
        stack<int> stk;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            while (!stk.empty() &&
                   (i == n || heights[stk.top()] >= heights[i])) {
                int h = heights[stk.top()];
                stk.pop();
                int w;
                if (stk.empty())
                    w = i;
                else
                    w = i - stk.top() - 1;
                ans = max(ans, h * w);
            }
            stk.push(i);
        }
        return ans;
    }
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        // int n = matrix.size();
        // int m = matrix[0].size();
        vector<int> heights(m, 0);
        int ans = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (matrix[r][c])
                    heights[c]++;
                else
                    heights[c] = 0;
            }
            int val = largestRectangleInHistogram(heights, m);
            ans = max(ans, val);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends