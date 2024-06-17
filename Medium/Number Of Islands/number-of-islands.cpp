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

// User function Template for C++
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m);
        vector<vector<int>> visited(n, vector<int>(m,0));
        vector<int> ans;
        int components = 0;
        vector<int> delx = {-1,1,0,0};
        vector<int> dely = {0,0,-1,1};
        for (auto it:operators){
            int x = it[0];
            int y = it[1];
            int u = x * m + y;
            if (visited[x][y]) { 
                ans.push_back(components);
                continue;
            }
            visited[x][y] = 1;
            components++;
            for (int i = 0; i < 4; i++){
                int newx = x + delx[i];
                int newy = y + dely[i];
                int v = newx * m + newy;
                if (newx >= 0 && newy >= 0 && newx < n && newy < m){
                    if (visited[newx][newy] == 1 && ds.findp(u) != ds.findp(v)){
                        components--;
                        ds.unionBySize(u,v);
                    }
                }
            }
            ans.push_back(components);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends