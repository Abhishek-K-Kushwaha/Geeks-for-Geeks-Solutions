//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> sizevec, parent;
    public:
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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        set<pair<int,pair<int, int>>> edges; //{weight, node1, node2}
        for (int node = 0; node < V; node++){
            for (auto it: adj[node]){
                int u = it[0];
                int w = it[1];
                edges.insert({w,{node, u}});
            }
        }
        int ans = 0;
        DisjointSet ds(V);
        for (auto it: edges){
            int w = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if (ds.findp(u) != ds.findp(v)){
                ans += w; 
                ds.unionBySize(u,v);
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends