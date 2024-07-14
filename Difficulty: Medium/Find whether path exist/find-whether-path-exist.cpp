//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        pair<int,int> src, dst;
        int n = grid.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    src = {i,j};
                }
                else if (grid[i][j] == 2){
                    dst = {i,j};
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push(src);
        visited[src.first][src.second] = true;
        vector<int> dx = {0,0,-1,1};
        vector<int> dy = {-1,1,0,0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for (int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (newx >= 0 && newy >= 0 && newx < n && newy < n && !visited[newx][newy]){
                    if (grid[newx][newy] == 2) return true;
                    if (grid[newx][newy] == 3){
                        q.push({newx, newy});
                        visited[newx][newy] = true;
                    }
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends