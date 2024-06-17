//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
    public:
    vector<int> sizevec, parent;

    DisjointSet(int n){
        sizevec.resize(n+1, 1);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int findp(int node){
        if (node == parent[node]) return node;
        return parent[node] = findp(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int paru = findp(u);
        int parv = findp(v);
        if (paru == parv) return;
        if (sizevec[paru] < sizevec[parv]){
            parent[paru] = parv;
            sizevec[parv] += sizevec[paru];
        }
        else{
            parent[parv] = paru;
            sizevec[paru] += sizevec[parv];
        }
    }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxrow = 0;
        int maxcol = 0;
        for (auto it : stones) {
            if (it[0] > maxrow)
                maxrow = it[0];
            if (it[1] > maxcol)
                maxcol = it[1];
        }
        DisjointSet ds(maxrow + 1 + maxcol + 1);
        for (auto it : stones) {
            int u = it[0];
            int v = it[1] + maxrow + 1;
            ds.unionBySize(u, v);
        }
        int components = 0;
        for (int i = 0; i <= maxrow+maxcol+1; i++) {
            if (ds.parent[i] == i && ds.sizevec[i] > 1)
                components++;
        }
        return n - components;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends