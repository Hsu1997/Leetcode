#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    row[i]++, col[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    if (row[i] != 1 || col[j] != 1) ans++;
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,0},{0,1}};
    // vector<vector<int>> grid = {{1,0},{1,1}};
    // vector<vector<int>> grid = {{1,1,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    Solution S;
    cout << S.countServers(grid) << endl;
    return 0;
}