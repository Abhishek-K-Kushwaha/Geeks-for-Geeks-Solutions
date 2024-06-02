//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<char>> fill(int m, int n, vector<vector<char>> board)
    {
        queue<pair<int,int>> q;
        vector<pair<int,int>> zeros;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (board[i][j] == 'O') {
                    if (i == 0 || j == 0 || i == m-1 || j == n-1){
                        q.push({i,j});
                    }
                    else {
                        board[i][j] = '1';
                        zeros.push_back({i,j});
                    }
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vector<int> delx = {0,0,1,-1};
            vector<int> dely = {1,-1,0,0};
            for (int i = 0; i < 4; i++){
                int newx = x + delx[i];
                int newy = y + dely[i];
                if (newx >= 0 && newx < m && newy >= 0 && newy < n && board[newx][newy] == '1'){
                    board[newx][newy] = 'O';
                    q.push({newx,newy});
                }
            }
        }
        for (auto it:zeros){
            if (board[it.first][it.second] == '1'){
                board[it.first][it.second] = 'X';
            }
        }
        return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends