//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        vector<int> delx = {-1, 1, 0, 0};
        vector<int> dely = {0, 0, -1, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    int u = i * n + j;
                    for (int k = 0; k < 4; k++) {
                        int newi = i + delx[k];
                        int newj = j + dely[k];
                        int v = newi * n + newj;
                        if (newi >= 0 && newj >= 0 && newi < n && newj < n) {
                            if (grid[newi][newj] &&
                                ds.findp(u) != ds.findp(v)) {
                                ds.unionBySize(u, v);
                            }
                        }
                    }
                }
            }
        }
        int maxans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int ans = 1;
                if (grid[i][j] == 0) {
                    int u = i * n + j;
                    set<int> ultimateparent;
                    for (int k = 0; k < 4; k++) {
                        int newi = i + delx[k];
                        int newj = j + dely[k];
                        int v = newi * n + newj;
                        if (newi >= 0 && newj >= 0 && newi < n && newj < n) {
                            if (grid[newi][newj]) {
                                ultimateparent.insert(ds.findp(v));
                            }
                        }
                    }
                    for (int par : ultimateparent) {
                        ans += ds.sizevec[par];
                    }
                }
                maxans = max(ans, maxans);
            }
        }
        return max(maxans, ds.sizevec[0]);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends