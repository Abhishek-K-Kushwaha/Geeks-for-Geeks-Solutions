//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int topDown(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 1;
        long long prev = 0;
        for (int i = 2; i <= n; i++){
            int next = (ans + prev)%MOD;
            prev = ans;
            ans = next;
        }
        return ans%MOD;
    }
    long long int bottomUp(int n) {
        const int MOD = 1e9 + 7;
        long long ans = 1;
        long long prev = 0;
        for (int i = 2; i <= n; i++){
            int next = (ans + prev)%MOD;
            prev = ans;
            ans = next;
        }
        return ans%MOD;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends