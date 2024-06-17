//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        unordered_map<string, int> mpp;
        DisjointSet ds(n);
        for (int acc = 0; acc < n; acc++) {
            for (int i = 1; i < accounts[acc].size(); i++) {
                string mail = accounts[acc][i];
                if (mpp.find(mail) == mpp.end()) {
                    mpp[mail] = acc;
                } else {
                    ds.unionBySize(acc, mpp[mail]);
                }
            }
        }
        vector<vector<string>> merged(n);
        for (auto it : mpp) {
            string mail = it.first;
            int node = ds.findp(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (merged[i].size() == 0)
                continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : merged[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> accounts;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            accounts.push_back(temp);
        }

        ///
        Solution obj;
        vector<vector<string>> res = obj.accountsMerge(accounts);
        sort(res.begin(), res.end());
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], " << endl;
            else
                cout << "]";
        }
        cout << "]" << endl;
    }
}
// } Driver Code Ends