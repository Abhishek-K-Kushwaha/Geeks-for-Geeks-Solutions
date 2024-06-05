//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> outdegree(V);
        vector<vector<int>> revadj(V);
        for (int i = 0; i < V; i++){
            for (int node:adj[i]){
                revadj[node].push_back(i);
                outdegree[i]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++){
            if (outdegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for (auto nxt:revadj[node]){
                outdegree[nxt]--;
                if (outdegree[nxt] == 0) q.push(nxt);
            }
            ans.push_back(node);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends