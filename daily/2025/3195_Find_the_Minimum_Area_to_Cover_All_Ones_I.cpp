#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int left = n;
        int right = 0;
        int top = m;
        int down = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    down = max(down, i);
                }
            }
        }
        return (down - top + 1) * (right - left + 1);
    }
};

int main(){
    vector<vector<int>> grid = {{0,1,0},{1,0,1}};
    // vector<vector<int>> grid = {{1,0},{0,0}};
    Solution S;
    cout << S.minimumArea(grid) << endl;
    return 0;
}