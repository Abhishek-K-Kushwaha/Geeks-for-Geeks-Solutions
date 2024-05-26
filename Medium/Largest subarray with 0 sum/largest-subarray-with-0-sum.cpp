//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        int largest = 0;
        unordered_map<int,int> dict;
        int presum = 0;
        for (int i = 0; i < n; i++){
            presum += arr[i];
            if (presum == 0){
                largest = max(largest, i+1);
            }
            if (dict.find(presum) != dict.end()){
                largest = max(largest, i - dict[presum]);
            }
            else {
                dict[presum] = i;
            }
        }
        return largest;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends