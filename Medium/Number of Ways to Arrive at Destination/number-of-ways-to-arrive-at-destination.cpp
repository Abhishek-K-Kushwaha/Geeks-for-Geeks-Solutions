//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto eg : roads) {
            int u = eg[0];
            int v = eg[1];
            int w = eg[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<long long> dist(n, INT_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        
        set<pair<long long, int>> st; // {distance, node}
        st.insert({0, 0});
        
        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);
            long long d = it.first;
            int node = it.second;
            
            for (auto nxt : adj[node]) {
                int nxtnode = nxt.first;
                long long nxtd = nxt.second;
                
                if (nxtd + d == dist[nxtnode]) {
                    ways[nxtnode] += ways[node];
                    ways[nxtnode] %= mod;
                } else if (nxtd + d < dist[nxtnode]) {
                    ways[nxtnode] = ways[node];
                    dist[nxtnode] = d + nxtd;
                    st.insert({d + nxtd, nxtnode});
                }
            }
        }
        
        return ways[n - 1];
    }
};



//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends