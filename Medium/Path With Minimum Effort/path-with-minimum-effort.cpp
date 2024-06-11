//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        // int n = heights.size();
        // int m = heights[0].size();
        set<pair<int, pair<int, int>>> st;
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        st.insert({0, {0, 0}});
        vector<int> delx = {0, 0, -1, 1};
        vector<int> dely = {1, -1, 0, 0};
        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);
            int maxdiff = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if (x == n - 1 && y == m - 1)
                return maxdiff;
            for (int i = 0; i < 4; i++) {
                int newx = x + delx[i];
                int newy = y + dely[i];
                if (newx >= 0 && newy >= 0 && newx < n && newy < m) {
                    int diff = abs(heights[x][y] - heights[newx][newy]);
                    int neweffort = max(diff, maxdiff);
                    if (neweffort < effort[newx][newy]) {
                        effort[newx][newy] = neweffort;
                        st.insert({neweffort, {newx, newy}});
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends