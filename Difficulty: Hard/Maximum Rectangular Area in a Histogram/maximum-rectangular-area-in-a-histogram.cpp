//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        stack<int> stk;
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            while (!stk.empty() &&
                   (i == n || heights[stk.top()] >= heights[i])) {
                long long h = heights[stk.top()];
                stk.pop();
                long long w;
                if (stk.empty())
                    w = i;
                else
                    w = i - stk.top() - 1;
                ans = max(ans, h * w);
            }
            stk.push(i);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends