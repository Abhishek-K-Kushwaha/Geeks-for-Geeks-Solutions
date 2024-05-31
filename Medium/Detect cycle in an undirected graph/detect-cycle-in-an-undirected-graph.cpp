//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(vector<int>& visited, vector<int> adj[], int src){
        queue<vector<int>> q;
        q.push({src,-1}); // Start BFS from node 0
        visited[src] = 1;
        while (!q.empty()) {
            int node = q.front()[0];
            int parent = q.front()[1];
            q.pop();
            for (auto nxt : adj[node]) {
                if (visited[nxt]) {
                    if (nxt != parent) 
                    return true;
                }
                else {
                    visited[nxt] = 1;
                    q.push({nxt,node});
                }
            }
        }
        return false; // No cycle found
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0); // Initialize visited vector
        for (int i = 0; i < V; i++){
            if (!visited[i] && bfs(visited,adj,i)){
                return true;
            }
        }
        return false;
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
