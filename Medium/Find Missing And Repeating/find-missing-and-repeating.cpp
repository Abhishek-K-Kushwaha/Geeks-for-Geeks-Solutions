//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        unordered_map<int,int> dict;
        vector<int> ans;
        long long sum = 0;
        for (int num:arr){
            sum += num;
            dict[num]++;
            if (dict[num] == 2){
                ans.push_back(num);
            }
        }
        long long nsum = (long long)n*(n+1)/2;
        ans.push_back(nsum - sum + ans[0]);
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