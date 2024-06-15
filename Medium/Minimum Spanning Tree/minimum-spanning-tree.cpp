//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        set<pair<int,int>> st; //{weight, node}
        vector<int> visited(V, 0);
        st.insert({0,0});
        int ans = 0;
        int cnt = 0;
        while (!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            int wt = it.first;
            int node = it.second;
            if (visited[node] == 1) continue;
            ans += wt;
            visited[node] = 1;
            if (cnt++ == V) break;
            
            for (auto nxt:adj[node]){
                int nxtnode = nxt[0];
                int w = nxt[1];
                if (visited[nxtnode] == 0) st.insert({w,nxtnode});
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