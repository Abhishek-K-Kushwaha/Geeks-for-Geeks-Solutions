//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n,0));
        queue<pair<int,int>> q;
        int cnt = 0;
        vector<int> delx = { 0,0,1,-1,-1,-1,1,1};
        vector<int> dely = {-1,1,0, 0,-1,1,-1,1};
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && visited[i][j] == 0){
                    cnt++;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while (!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for (int nxt = 0; nxt < 8; nxt++){
                            int newx = x + delx[nxt];
                            int newy = y + dely[nxt];
                            if (newx >= 0 && newy >= 0 && newx < m && newy < n && visited[newx][newy] == 0 && grid[newx][newy] == '1'){
                                visited[newx][newy] = 1;
                                q.push({newx,newy});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends