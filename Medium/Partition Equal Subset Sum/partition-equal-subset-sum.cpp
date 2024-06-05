//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int nums[])
    {
        int sum = 0;
        //int n = nums.size();
        if (n == 1)
            return false;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        else
            sum = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= sum)
            dp[0][nums[0]] = true;
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 1; tar <= sum; tar++) {
                bool nottake = dp[ind - 1][tar];
                bool take = false;
                if (tar >= nums[ind])
                    take = dp[ind - 1][tar - nums[ind]];
                dp[ind][tar] = (nottake || take);
            }
        }
        return dp[n - 1][sum];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends