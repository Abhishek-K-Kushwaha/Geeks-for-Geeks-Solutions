//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node, vector<int>& visited, vector<vector<int>>& adj, stack<int>& stk){
	    visited[node] = 1;
	    for (auto nxt:adj[node]){
	        if (!visited[nxt]){
	            dfs(nxt, visited, adj, stk);
	            //stk.push(nxt);
	        }
	    }
	    stk.push(node);
	}
	
	void dfsorg(int node, vector<int>& visited, vector<vector<int>>& adj){
	    visited[node] = 1;
	    for (auto nxt:adj[node]){
	        if (!visited[nxt]){
	            dfsorg(nxt, visited, adj);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visited(V, 0);
        stack<int> stk;
        for (int i = 0; i < V; i++){
            if (!visited[i]){
                dfs(i, visited, adj, stk);
            }
        }
        vector<vector<int>> revadj(V);
        for (int i = 0; i < V; i++){
            visited[i] = 0;
            for (int j:adj[i]){
                revadj[j].push_back(i);
            }
        }
        int ans = 0;
        for (int i = 0; i < V; i++){
            int node = stk.top();
            stk.pop();
            if (!visited[node]){
                ans++;
                dfsorg(node, visited, revadj);
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
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends