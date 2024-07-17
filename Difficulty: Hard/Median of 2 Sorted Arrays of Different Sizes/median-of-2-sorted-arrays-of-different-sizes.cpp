//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return MedianOfArrays(nums2, nums1);
        int i = 0;
        int j = m;
        while (i <= j) {
            int mid1 = i + (j - i) / 2;
            int mid2 = (m + n + 1) / 2 - mid1;
            double l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid1 < m)
                r1 = nums1[mid1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            if (mid2 < n)
                r2 = nums2[mid2];

            if (l1 > r2) {
                j = mid1 - 1;
            } else if (l2 > r1) {
                i = mid1 + 1;
            } else {
                if ((m + n) % 2)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2;
            }
        }
        return -1;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends