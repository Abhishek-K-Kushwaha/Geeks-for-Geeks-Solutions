//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int N, int K)
    {
        unordered_map<int, int> dict;
        int count = 0;
        int pre_sum = 0;
        for (int i = 0; i < N; i++) {
            pre_sum += arr[i];
            if (pre_sum == K) {
                count++;
            }
            count += dict[pre_sum - K];
            dict[pre_sum]++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends