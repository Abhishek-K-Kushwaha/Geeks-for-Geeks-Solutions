//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int> ans;
        long long ns = (long long)n*(n+1)/2;
        long long ns2 = (long long)n*(n+1)*(2*n+1)/6;
        long long sum = 0;
        long long sum2 = 0;
        for (int num:arr){
            sum += num;
            sum2 += (long long)num*num;
        }
        long long ndiff = ns - sum;
        long long ndiff2 = ns2 - sum2;
        ans.push_back((ndiff2/ndiff - ndiff)/2);
        ans.push_back(ndiff + ans[0]);
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends