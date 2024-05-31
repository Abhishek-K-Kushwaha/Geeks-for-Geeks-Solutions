//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, int n, vector<int>& visited,vector<vector<int>>& isConnected) {
        visited[node] = 1;
        for (int j = 0; j < n; j++) {
            if (j != node && isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, n, visited, isConnected);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> isConnected, int n) {
        vector<int> visited(n);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, n, visited, isConnected);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends