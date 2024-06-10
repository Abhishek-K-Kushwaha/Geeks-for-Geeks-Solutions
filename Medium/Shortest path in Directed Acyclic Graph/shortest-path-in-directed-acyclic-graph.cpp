//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<vector<pair<int,int>>> adj(N);
        for (auto eg: edges){
            adj[eg[0]].push_back({eg[1], eg[2]});
        }
        vector<int> dist(N,INT_MAX);
        queue<int> q;
        dist[0] = 0;
        q.push(0);
        while (!q.empty()){
            int node = q.front();
            int d = dist[node];
            q.pop();
            for (auto nxt: adj[node]){
                if (dist[nxt.first] > d + nxt.second){
                    dist[nxt.first] = d + nxt.second;
                    q.push(nxt.first);
                }
            }
        }
        for (int i = 1; i < N; i++){
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends