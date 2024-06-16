//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int node, vector<int>& visited, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nxt : adj[node]) {
                if (!visited[nxt]) {
                    q.push(nxt);
                    visited[nxt] = 1;
                }
            }
        }
    }
    
    int Solve(int n, vector<vector<int>>& connections) {
        int cables = connections.size();
        if (cables < n - 1)
            return -1;
        vector<int> visited(n, 0);
        vector<vector<int>> adj(n);
        for (auto eg : connections) {
            adj[eg[0]].push_back(eg[1]);
            adj[eg[1]].push_back(eg[0]);
        }
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                components++;
                bfs(i, visited, adj);
            }
        }
        return components - 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends