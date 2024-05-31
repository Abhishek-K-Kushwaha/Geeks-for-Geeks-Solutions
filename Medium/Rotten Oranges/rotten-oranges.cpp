//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    
    int bfs(int fresh, vector<vector<int>>& grid, queue<vector<int>>& q) {
        int mintime = 0;
        int m = grid.size();
        int n = grid[0].size();
        while (!q.empty()) {
            vector<int> point = q.front();
            q.pop();
            int r = point[0]; // row
            int c = point[1]; // column
            int t = point[2]; // time
            if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                grid[r - 1][c] = 2;
                fresh--;
                q.push({r - 1, c, t + 1});
                mintime = max(mintime, t + 1);
            }
            if (r + 1 < m && grid[r + 1][c] == 1) {
                grid[r + 1][c] = 2;
                fresh--;
                q.push({r + 1, c, t + 1});
                mintime = max(mintime, t + 1);
            }
            if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                grid[r][c - 1] = 2;
                fresh--;
                q.push({r, c - 1, t + 1});
                mintime = max(mintime, t + 1);
            }
            if (c + 1 < n && grid[r][c + 1] == 1) {
                grid[r][c + 1] = 2;
                fresh--;
                q.push({r, c + 1, t + 1});
                mintime = max(mintime, t + 1);
            }
        }
        if (fresh != 0)
            return -1;
        else
            return mintime;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        queue<vector<int>> q; //{row, column, time}
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2) {
                    vector<int> cord = {i, j, 0};
                    q.push(cord);
                }
            }
        }
        if (fresh == 0)
            return 0;
        return bfs(fresh, grid, q);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends