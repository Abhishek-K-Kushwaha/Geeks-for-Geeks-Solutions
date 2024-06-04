//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int n, vector<int>graph[]){
        vector<int> visited(n,-1);
        queue<int> q;
        for (int i = 0; i < n; i++){
            if (visited[i] == -1){
                q.push(i);
                visited[i] = 0;
                while (!q.empty()){
                    int node = q.front();
                    int color = visited[node];
                    q.pop();
                    for (int nxt:graph[node]){
                        if (visited[nxt] == -1){
                            if (color){
                                visited[nxt] = 0;
                            }
                            else{
                                visited[nxt] = 1;
                            }
                            q.push(nxt);
                        }
                        else if (visited[nxt] == color) return false;
                    }
                }
            }
        }
        return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends