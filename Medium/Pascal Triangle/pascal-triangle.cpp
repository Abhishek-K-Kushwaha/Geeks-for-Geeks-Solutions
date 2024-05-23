//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    long long modularInverse(long long a, long long mod) {
        long long result = 1;
        long long power = mod - 2;
    
        while (power > 0) {
            if (power % 2 == 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            power /= 2;
        }
    
        return result;
    }

    vector<long long> nthRowOfPascalTriangle(int n) {
        const long long MOD = 1e9 + 7;
        vector<long long> triangle = {1};
        long long num = 1;
        
        for (int j = 1; j < n; j++) {
            num = (num * (n - j)) % MOD;
            num = (num * modularInverse(j, MOD)) % MOD;
            triangle.push_back(num);
        }
    
        return triangle;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends