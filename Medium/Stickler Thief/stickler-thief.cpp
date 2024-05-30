//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int nums[], int n)
    {
        //int n = nums.size();
        if (n == 1)
            return nums[0];
        int prev = max(nums[0], nums[1]);
        int prev2 = nums[0];
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + prev2;
            int notpick = 0 + prev;
            int temp = max(pick, notpick);
            prev2 = prev;
            prev = temp;
        }
        return prev;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends