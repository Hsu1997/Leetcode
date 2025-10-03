#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Cell{
public:
    int height;
    int row;
    int col;
    Cell(int height, int row, int col) : height(height), row(row), col(col) {}
    bool operator<(const Cell& other) const{
        return height >= other.height;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};
        priority_queue<Cell> boundary;
        for (int i = 0; i < m; i++){
            boundary.push(Cell(heightMap[i][0], i, 0));
            boundary.push(Cell(heightMap[i][n-1], i, n-1));
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        for (int j = 1; j < n - 1; j++){
            boundary.push(Cell(heightMap[0][j], 0, j));
            boundary.push(Cell(heightMap[m-1][j], m-1, j));
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        int water = 0;

        auto infield = [&](int i, int j){
            return i >= 0 && j >= 0 && i < m && j < n;
        };

        while(!boundary.empty()){
            Cell currCell = boundary.top();
            boundary.pop();
            int currRow = currCell.row;
            int currCol = currCell.col;
            int currHeight = currCell.height;
            for (int d = 0; d < 4; d++){
                int newRow = currRow + dr[d];
                int newCol = currCol + dc[d];
                if (infield(newRow, newCol) && !visited[newRow][newCol]){
                    int neighborHeight = heightMap[newRow][newCol];
                    if (neighborHeight < currHeight) water += currHeight - neighborHeight;
                    boundary.push(Cell(max(currHeight, neighborHeight), newRow, newCol));
                    visited[newRow][newCol] = true;
                }
            }
        }
        return water;
    }
};

int main(){
    vector<vector<int>> heightMap = {{1,4,3,1,3,2},{3,2,1,3,2,4},{2,3,3,2,3,1}};
    // vector<vector<int>> heightMap = {{3,3,3,3,3},{3,2,2,2,3},{3,2,1,2,3},{3,2,2,2,3},{3,3,3,3,3}};
    Solution S;
    cout << S.trapRainWater(heightMap) << endl;
    return 0;
}