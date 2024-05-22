//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int N)
    {
        string str;
        long long rem;
        while (N!=0){
            rem = (N-1)%26;
            str += (rem + 'A');
            N = (N-1)/26 ;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends