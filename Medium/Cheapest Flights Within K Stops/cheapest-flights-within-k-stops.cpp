//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<vector<pair<int, int>>> adj(n);
        for (auto eg : flights) {
            adj[eg[0]].push_back({eg[1], eg[2]});
        }
        queue<pair<int, pair<int, int>>> q; //{stops,{node,cost}}
        vector<int> cost(n, INT_MAX);
        q.push({0, {src, 0}});
        cost[src] = 0;
        while (!q.empty()) {
            int stp = q.front().first;
            int node = q.front().second.first;
            int cst = q.front().second.second;
            q.pop();
            if (stp > k)
                break;
            for (auto nxt : adj[node]) {
                int nxtnode = nxt.first;
                int nxtcst = nxt.second;
                if (nxtcst + cst < cost[nxtnode]) {
                    cost[nxtnode] = nxtcst + cst;
                    q.push({stp + 1, {nxtnode, nxtcst + cst}});
                }
            }
        }

        if (cost[dst] == INT_MAX)
            return -1;
        else
            return cost[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends