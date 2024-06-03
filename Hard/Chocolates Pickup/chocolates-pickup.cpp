//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int row, int col1, int col2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if (col1 < 0 || col1 >= m || col2 < 0 || col2 >= m) return INT_MIN;
        if (dp[row][col1][col2] != -1) return dp[row][col1][col2];
        if (n-1 == row) {
            if (col1 != col2) return dp[row][col1][col2]  = grid[row][col1] + grid[row][col2];
            else return dp[row][col1][col2]  = grid[row][col1];
        }
        vector<int> del = {-1,0,1};
        int maxval = 0;
        for (int d1:del){
            for (int d2:del){
                int newcol1 = col1 + d1;
                int newcol2 = col2 + d2;
                int val = f(row+1,newcol1,newcol2,n,m,grid,dp);
                if (col1 != col2) val += grid[row][col1] + grid[row][col2] ;
                else val += grid[row][col1];
                maxval = max(maxval,val);
            }
        }
        return dp[row][col1][col2]  = maxval;
        
        
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(m,-1)));
        return f(0,0, m-1,n,m,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends