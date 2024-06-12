//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end) return 0;
        vector<int> steps(1e5,INT_MAX);
        queue<pair<int,int>> q; //{steps,node}
        q.push({0,start});
        steps[start] = 0;
        while (!q.empty()){
            int stp = q.front().first;
            int node = q.front().second;
            q.pop();
            for (int i:arr){
                int newnode = (node * i % 100000);
                if (newnode == end) return stp + 1;
                if (steps[newnode] == INT_MAX){
                    steps[newnode] = stp + 1;
                    q.push({stp+1, newnode});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends