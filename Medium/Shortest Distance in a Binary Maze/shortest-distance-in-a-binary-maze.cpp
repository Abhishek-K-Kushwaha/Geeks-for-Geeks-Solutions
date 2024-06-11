//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if (grid[source.first][source.second] == 0)
            return -1;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        q.push(source);
        dist[source.first][source.second] = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int d = dist[x][y];
            vector<int> delx = {0, 0, 1, -1};
            vector<int> dely = {-1, 1, 0, 0};
            for (int i = 0; i < 4; i++) {
                int newx = x + delx[i];
                int newy = y + dely[i];
                if (newx >= 0 && newy >= 0 && newx < n && newy < m &&
                    grid[newx][newy] == 1 && dist[newx][newy] > d + 1) {
                    dist[newx][newy] = d + 1;
                    q.push({newx, newy});
                }
            }
        }
        if (dist[destination.first][destination.second] == INT_MAX)
            return -1;
        else
            return dist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends