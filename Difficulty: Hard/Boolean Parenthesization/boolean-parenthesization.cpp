//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1003;
    int f(int i, int j,int istrue, string& exp, vector<vector<vector<long long>>>& dp){
        if (i > j) return 0;
        if (dp[i][j][istrue] != -1) return dp[i][j][istrue];
        if (i == j){
            if (istrue) return dp[i][j][istrue] = (exp[i] == 'T');
            else return dp[i][j][istrue] = (exp[i] == 'F');
        }
        long long ans = 0;
        for (int k = i+1; k <= j-1; k = k+2){
            long long ltrue = f(i, k-1, 1, exp, dp);
            long long rtrue = f(k+1, j, 1,exp, dp);
            long long lfalse = f(i, k-1, 0, exp, dp);
            long long rfalse = f(k+1,j,0, exp, dp);
            if (exp[k] == '&'){
                if (istrue) ans += (ltrue*rtrue);
                else ans += (lfalse*rfalse + ltrue*rfalse + lfalse*rtrue);
            } 
            else if (exp[k] == '|'){
                if (istrue) ans += (ltrue*rtrue + ltrue*rfalse + lfalse*rtrue);
                else ans += lfalse*rfalse;
            }
            else{
                if (istrue) ans += (ltrue*rfalse + lfalse*rtrue);
                else ans+= (ltrue*rtrue + lfalse*rfalse);
            }
        }
        return dp[i][j][istrue] = ans % mod;
    }
    
    int countWays(int n, string exp){
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2,-1)));
        return f(0,n-1, 1, exp, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends