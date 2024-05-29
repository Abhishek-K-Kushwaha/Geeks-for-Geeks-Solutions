//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& h, int n) {
        int enrg2 = abs(h[0] - h[1]);
        int enrg1 = min(abs(h[0] - h[2]), abs(h[0] - h[1]) + abs(h[1] - h[2]));
        if (n == 1) return 0;
        if (n == 2) return enrg2;
        if (n == 3) return enrg1;
        
        for (int i = 4; i <= n; i++){
            int temp1 = enrg1 + abs(h[i-1] - h[i-2]);
            int temp2 = enrg2 + abs(h[i-3] - h[i-1]);
            enrg2 = enrg1;
            enrg1 = min(temp1,temp2);
        }
        return enrg1;
        
        // int enrg1 = minimumEnergy(h, n-1) + abs(h[n-1] - h[n-2]);
        // int enrg2 = minimumEnergy(h, n-2) + min(abs(h[n-3] - h[n-1]), abs(h[n-3] - h[n-2]) + abs(h[n-2] - h[n-1]));
        // return min(enrg1, enrg2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
