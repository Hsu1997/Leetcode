#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int n;

    bool in_grid(int i, int j){
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    void extend(vector<vector<int>>& grid, vector<vector<int>>& first_land_grid){
        vector<vector<int>> extended_grid = grid;
        vector<vector<int>> extended_first_land_grid = first_land_grid;
        vector<int> x = {-1,0,1,0};
        vector<int> y = {0,1,0,-1};
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (first_land_grid[i][j]){
                    extended_grid[i][j] = 1;
                    extended_first_land_grid[i][j] = 1;
                    for (int k = 0; k < 4; k++){
                        if (in_grid(i+x[k], j+y[k])){
                            extended_grid[i+x[k]][j+y[k]] = 1;
                            extended_first_land_grid[i+x[k]][j+y[k]] = 1;
                        }
                    }
                }
            }
        }
        swap(grid, extended_grid);
        swap(first_land_grid, extended_first_land_grid);
    }

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, int& count){
        count++;
        visited[i][j] = 1;
        vector<int> x = {-1,0,1,0};
        vector<int> y = {0,1,0,-1};
        for (int k = 0; k < 4; k++){
            int new_i = i + x[k];
            int new_j = j + y[k];
            if (in_grid(new_i, new_j) && grid[new_i][new_j] && !visited[new_i][new_j]) dfs(new_i, new_j, grid, visited, count);
        }
    }

    bool one_land(vector<vector<int>>& grid){
        bool find_first = false;
        int first_i = -1;
        int first_j = -1;
        int land = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]){
                    first_i = i, first_j = j, find_first = true;
                    land++;
                }
            }
        }
        vector<vector<int>> visited(n, vector<int>(n, false));
        int count = 0;
        dfs(first_i, first_j, grid, visited, count);
        if (count == land) return true;
        return false;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = 0;

        bool find_first = false;
        int first_i = -1;
        int first_j = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j]){
                    first_i = i, first_j = j, find_first = true;
                    if (find_first) break;
                }
            }
            if (find_first) break;
        }
        vector<vector<int>> first_land_grid(n, vector<int>(n, 0));
        int c = 0;
        dfs(first_i, first_j, grid, first_land_grid, c);

        while(!one_land(grid)){
            extend(grid, first_land_grid);
            ans++;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{0,1},{1,0}};
    // vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}};
    Solution S;
    cout << S.shortestBridge(grid) << endl;
    return 0;
}