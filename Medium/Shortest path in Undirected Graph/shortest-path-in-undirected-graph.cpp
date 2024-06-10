//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        for (auto eg:edges){
            adj[eg[0]].push_back(eg[1]);
            adj[eg[1]].push_back(eg[0]);
        }
        
        queue<int> q;
        vector<int> d(N,-1);
        d[src] = 0;
        q.push(src);
        while (!q.empty()){
            int node = q.front();
            int dist = d[node];
            q.pop();
            for (auto nxt:adj[node]){
                if (d[nxt] == -1){
                    d[nxt] = dist + 1;
                    q.push(nxt);
                }
            }
        }
        return d;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends