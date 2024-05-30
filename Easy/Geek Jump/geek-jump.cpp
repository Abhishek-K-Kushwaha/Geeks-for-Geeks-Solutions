//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& h, int n) {
        int enrg2 = 0;
        int enrg1 = abs(h[0] - h[1]);
        if (n == 1) return enrg2;
        if (n == 2) return enrg1;

        for (int i = 3; i <= n; i++){
            int temp1 = enrg1 + abs(h[i-1] - h[i-2]);
            int temp2 = enrg2 + abs(h[i-3] - h[i-1]);
            enrg2 = enrg1;
            enrg1 = min(temp1,temp2);
        }
        return enrg1;
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
