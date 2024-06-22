//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> matrix){
        vector<int> prev(m,0);
        vector<int> curr(m);
        int ans = 0;
        for (int r = 0; r < n; r++){
            for (int c = 0; c < m; c++){
                curr[c] = 0;
                if (r == 0 || c == 0){ 
                    curr[c] = matrix[r][c];
                }
                else if (matrix[r][c]){
                    curr[c] = 1 + min({curr[c-1], prev[c-1], prev[c]});
                }
                ans = max(ans,curr[c]);
            }
            prev = curr;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends