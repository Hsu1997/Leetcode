#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int m;
    int n;
    vector<vector<int>> height;
    vector<vector<bool>> Pacific;
    vector<vector<bool>> Atlantic;
    vector<int> x_d = {0,1,0,-1};
    vector<int> y_d = {1,0,-1,0};

    bool in_board(int i, int j){
        return (i >= 0) && (i < m) && (j >= 0) && (j < n);
    }

    void dfs(vector<vector<bool>>& sea, int i, int j){
        sea[i][j] = 1;
        for (int d = 0; d < 4; d++){
            int new_x = i + x_d[d];
            int new_y = j + y_d[d];
            if (in_board(new_x, new_y) && sea[new_x][new_y] == 0 && height[new_x][new_y] >= height[i][j]){
                dfs(sea, new_x, new_y);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        height = heights;
        m = heights.size();
        n = heights[0].size();
        Pacific = vector<vector<bool>>(m, vector<bool>(n, 0));
        Atlantic = vector<vector<bool>>(m, vector<bool>(n, 0));

        for (int i = 0; i < n; i++){
            dfs(Pacific, 0, i);
            dfs(Atlantic, m-1, i);
        }
        for (int i = 0; i < m; i++){
            dfs(Pacific, i, 0);
            dfs(Atlantic, i, n-1);
        }

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (Pacific[i][j] && Atlantic[i][j]) ans.push_back({i, j});
            }
        }

        return ans;
    }
};

int main(){
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    // vector<vector<int>> heights = {{1}};
    Solution S;
    vector<vector<int>> ans = S.pacificAtlantic(heights);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}