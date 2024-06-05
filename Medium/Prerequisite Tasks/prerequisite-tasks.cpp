//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int numCourses,int P, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for (auto edge : prerequisites) {
            adj[edge.second].push_back(edge.first);
            indegree[edge.first]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto nxt : adj[node]) {
                indegree[nxt]--;
                if (indegree[nxt] == 0)
                    q.push(nxt);
            }
            cnt++;
        }
        if (cnt == numCourses)
            return true;
        else
            return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends