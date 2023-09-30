#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0]) return 0;
        // obstacleGrid[0][0] = 1;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (obstacleGrid[i][j] == 1) obstacleGrid[i][j] = -1;
                else{
                    if (i > 0 && obstacleGrid[i-1][j] > 0) obstacleGrid[i][j] += obstacleGrid[i-1][j];
                    if (j > 0 && obstacleGrid[i][j-1] > 0) obstacleGrid[i][j] += obstacleGrid[i][j-1];
                    if (i == 0 && j == 0) obstacleGrid[i][j] = 1;
                }
            }
        }
        // for (auto i : obstacleGrid){
        //     for (auto j : i) cout << j << " ";
        //     cout << endl;
        // }
        return (obstacleGrid[m-1][n-1] == -1)? 0 : obstacleGrid[m-1][n-1];
    }
};

int main(){
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    // vector<vector<int>> obstacleGrid = {{0,1},{0,0}};
    Solution S;
    cout << S.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}