//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>> mat)
	{
	    int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1)); // initialize with -1
        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            //int d = q.front()[2];
            int d = ans[x][y];
            q.pop();
            if (x - 1 >= 0 && ans[x - 1][y] == -1) {
                ans[x - 1][y] = d + 1;
                q.push({x - 1, y});
            }
            if (x + 1 < m && ans[x + 1][y] == -1) {
                ans[x + 1][y] = d + 1;
                q.push({x + 1, y});
            }

            if (y - 1 >= 0 && ans[x][y - 1] == -1) {
                ans[x][y - 1] = d + 1;
                q.push({x, y - 1});
            }
            if (y + 1 < n && ans[x][y + 1] == -1) {
                ans[x][y + 1] = d + 1;
                q.push({x, y + 1});
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends