#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        for (int i = 0; i + k - 1 < m; i++){
            for (int j = 0; j + k - 1 < n; j++){
                set<int> curr;
                for (int x = i; x < i + k; x++){
                    for (int y = j; y < j + k; y++){
                        curr.insert(grid[x][y]);
                    }
                }
                if (curr.size() == 1){
                    ans[i][j] = 0;
                    continue;
                }
                int d = INT_MAX;
                for (auto it = curr.begin(); it != prev(curr.end()); it++){
                    auto nxt = next(it);
                    d = min(d, abs(*nxt - *it));
                }
                ans[i][j] = d;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,8},{3,-2}};
    int k = 2;
    // vector<vector<int>> grid = {{3,-1}};
    // int k = 1;
    // vector<vector<int>> grid = {{1,-2,3},{2,3,5}};
    // int k = 2;
    Solution S;
    vector<vector<int>> ans = S.minAbsDiff(grid, k);
    for (auto& row : ans){
        for (int col : row){
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}