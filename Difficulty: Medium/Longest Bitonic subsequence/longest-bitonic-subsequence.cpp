//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution { 
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp(n,1);
        vector<int> revdp(n,1);
        for (int i = 1; i < n; i++){
            int revi = n - 1 - i;
            for (int prev = 0; prev < i; prev++){
                int revprev = n - 1 - prev;
                
                if (nums[i] > nums[prev]){
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
                
                if (nums[revi] > nums[revprev]){
                    revdp[revi] = max(revdp[revi], 1 + revdp[revprev]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (ans < dp[i] + revdp[i] - 1 &&  dp[i] != 1 && revdp[i] != 1){
                ans = dp[i] + revdp[i] - 1;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> nums(n);
        Array::input(nums,n);
        
        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends