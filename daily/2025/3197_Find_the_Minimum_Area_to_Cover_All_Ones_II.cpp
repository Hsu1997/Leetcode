#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int m, n;
    int CoverAllArea(vector<vector<int>>& grid, int top, int down, int left, int right){
        int t = m;
        int d = 0;
        int l = n;
        int r = 0;
        for (int i = top; i <= down; i++){
            for (int j = left; j <= right; j++){
                if (grid[i][j]){
                    t = min(t, i);
                    d = max(d, i);
                    l = min(l, j);
                    r = max(r, j);
                }
            }
        }
        return (t < m)? (d - t + 1) * (r - l + 1) : 1000;
    }
    int minimumSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = INT_MAX;
        for (int i = 0; i + 1 < m; i++){
            for (int j = 0; j + 1 < n; j++){
                // (0, i, 0, j) (0, i, j+1, n-1) (i+1, m-1, 0, j) (i+1, m-1, j+1, n-1)
                ans = min({
                    ans, 
                    CoverAllArea(grid, 0, i, 0, n-1) + CoverAllArea(grid, i+1, m-1, 0, j) + CoverAllArea(grid, i+1, m-1, j+1, n-1),
                    CoverAllArea(grid, 0, m-1, 0, j) + CoverAllArea(grid, 0, i, j+1, n-1) + CoverAllArea(grid, i+1, m-1, j+1, n-1),
                    CoverAllArea(grid, 0, i, 0, j) + CoverAllArea(grid, 0, m-1, j+1, n-1) + CoverAllArea(grid, i+1, m-1, 0, j),
                    CoverAllArea(grid, 0, i, 0, j) + CoverAllArea(grid, 0, i, j+1, n-1) + CoverAllArea(grid, i+1, m-1, 0, n-1)
                });
            }
        }
        for (int i = 0; i + 2 < m; i++){
            for (int j = i + 1; j + 1 < m; j++){
                ans = min(ans, CoverAllArea(grid, 0, i, 0, n-1) + CoverAllArea(grid, i+1, j, 0, n-1) + CoverAllArea(grid, j+1, m-1, 0, n-1));
            }
        }
        for (int i = 0; i + 2 < n; i++){
            for (int j = i + 1; j + 1 < n; j++){
                ans = min(ans, CoverAllArea(grid, 0, m-1, 0, i) + CoverAllArea(grid, 0, m-1, i+1, j) + CoverAllArea(grid, 0, m-1, j+1, n-1));
            }
        }
        return ans;
    }
};

int main(){
    // vector<vector<int>> grid = {{1,0,1},{1,1,1}};
    vector<vector<int>> grid = {{1,0,1,0},{0,1,0,1}};
    Solution S;
    cout << S.minimumSum(grid) << endl;
    return 0;
}