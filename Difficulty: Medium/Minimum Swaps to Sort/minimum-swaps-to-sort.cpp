//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& vec) {
        // Code here
        int n = vec.size();
        vector<pair<int,int>> arr(n);
        vector<int> vis(n,0);
        for (int i = 0; i < n; i++){
            arr[i] = {vec[i], i};
        }
        sort(arr.begin(), arr.end());
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                vis[i] = 1;
                int ind = i;
                while (!vis[arr[ind].second]){
                    ans++;
                    vis[arr[ind].second] = 1;
                    ind = arr[ind].second;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends