//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& visited,
             vector<vector<int>>& ans, vector<vector<int>>& adj,
             vector<int>& tin, vector<int>& tlow) {
        visited[node] = 1;
        tin[node] = tlow[node] = timer;
        timer++;
        for (auto nxt : adj[node]) {
            if (nxt != parent) {
                if (!visited[nxt]) {
                    dfs(nxt, node, visited, ans, adj, tin, tlow);
                    tlow[node] = min(tlow[node], tlow[nxt]);
                    if (tlow[nxt] > tin[node]) {
                        vector<int> temp = {node, nxt};
                        sort(temp.begin(), temp.end());
                        ans.push_back(temp);
                    }
                } else {
                    tlow[node] = min(tlow[node], tlow[nxt]);
                }
            }
        }
    }
    
public:
	vector<vector<int>>criticalConnections(int n, vector<int> connections[]){
	    vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < connections[i].size(); j++) {
                int u = i;
                int v = connections[i][j];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        vector<int> visited(n, 0);
        vector<int> tin(n);
        vector<int> tlow(n);
        vector<vector<int>> ans;
        dfs(0, -1, visited, ans, adj, tin, tlow);
        sort(ans.begin(), ans.end());
        return ans;
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends