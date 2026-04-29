#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        vector<int> v;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] % x != grid[0][0] % x) return -1;
                v.push_back(grid[i][j] / x);
                total += grid[i][j] / x;
            }
        }
        sort(v.begin(), v.end());
        int s = v.size();
        int ans = 0;
        for (int i = 0; i < s; i++) ans += abs(v[i] - v[s/ 2]);
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{2,4},{6,8}};
    int x = 2;
    // vector<vector<int>> grid = {{1,5},{2,3}};
    // int x = 1;
    // vector<vector<int>> grid = {{1,2},{3,4}};
    // int x = 2;
    // vector<vector<int>> grid = {{931,128},{639,712}};
    // int x = 73;
    Solution S;
    cout << S.minOperations(grid, x) << endl;
    return 0;
}