#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total = 0;
        vector<long long> h(m, 0);
        vector<long long> v(n, 0);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                total += grid[i][j];
                h[i] += grid[i][j];
                v[j] += grid[i][j];
            }
        }
        long long acc = 0;
        for (int i = 0; i < m; i++){
            acc += h[i];
            if (acc == total - acc) return true;
        }
        acc = 0;
        for (int j = 0; j < n; j++){
            acc += v[j];
            if (acc == total - acc) return true;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> grid = {{1,4},{2,3}};
    // vector<vector<int>> grid = {{1,3},{2,4}};
    Solution S;
    cout << S.canPartitionGrid(grid) << endl;
    return 0;
}