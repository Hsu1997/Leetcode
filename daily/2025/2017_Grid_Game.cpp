#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long first_row = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long second_row = 0;
        long long min_ans = LLONG_MAX;
        for (int i = 0; i < n; i++){
            first_row -= grid[0][i];
            min_ans = min(min_ans, max(first_row, second_row));
            second_row += grid[1][i];
        }
        return min_ans;
    }
};

int main(){
    vector<vector<int>> grid = {{2,5,4},{1,5,1}};
    // vector<vector<int>> grid = {{3,3,1},{8,5,2}};
    // vector<vector<int>> grid = {{1,3,1,15},{1,3,3,1}};
    Solution S;
    cout << S.gridGame(grid) << endl;
    return 0;
}