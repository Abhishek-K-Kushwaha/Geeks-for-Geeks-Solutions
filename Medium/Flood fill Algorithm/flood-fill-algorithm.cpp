//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int prevColor = image[sr][sc];
    if (prevColor == newColor) return image; // No need to do anything if already the new color
    int m = image.size();
    int n = image[0].size();
    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        if (image[r][c] == prevColor) {
            image[r][c] = newColor;
            if (r - 1 >= 0) q.push(make_pair(r - 1, c)); // Up
            if (r + 1 < m) q.push(make_pair(r + 1, c)); // Down
            if (c - 1 >= 0) q.push(make_pair(r, c - 1)); // Left
            if (c + 1 < n) q.push(make_pair(r, c + 1)); // Right
        }
    }
    return image;
}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends