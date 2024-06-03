//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    const long long MOD = 1e9 + 7;

    long long mod_pow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    long long numberOfPaths(int m, int n) {
        long long N = m + n - 2;
        long long r = min(m, n) - 1;
    
        // Calculate (m-1) + (n-1) choose (m-1)
        long long ans = 1;
        for (int i = 1; i <= r; ++i) {
            ans = (ans * (N - i + 1)) % MOD;
            ans = (ans * mod_pow(i, MOD - 2)) % MOD; // Compute modular inverse
        }
    
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends