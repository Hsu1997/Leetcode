#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> horizontal(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> vertical(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                horizontal[i][j] = grid[i][j] + ((j > 0)? horizontal[i][j-1] : 0);
                vertical[i][j] = grid[i][j] + ((i > 0)? vertical[i-1][j] : 0);
            }
        }
        
        auto valid = [&](int i, int j, int k){
            int l = horizontal[i][j + k - 1] - ((j > 0)? horizontal[i][j-1] : 0);
            for (int d = 0; d < k; d++){
                if (horizontal[i + d][j + k - 1] - ((j > 0)? horizontal[i + d][j-1] : 0) != l) return false;
                if (vertical[i + k - 1][j + d] - ((i > 0)? vertical[i - 1][j + d] : 0) != l) return false;
            }
            int l1 = 0, l2 = 0;
            for (int d = 0; d < k; d++){
                l1 += grid[i + d][j + d];
                l2 += grid[i + d][j + k - 1 - d];
            }
            if (l1 != l || l2 != l) return false;
            return true;
        };

        auto check = [&](int k){
            for (int i = 0; i + k - 1 < m; i++){
                for (int j = 0; j + k - 1 < n; j++){
                    if (valid(i, j, k)) return true;
                }
            }
            return false;
        };

        for (int k = min(m, n); k > 1; k--){
            if (check(k)) return k;
        }
        return 1;
    }
};

int main(){
    vector<vector<int>> grid = {{7,1,4,5,6},{2,5,1,6,4},{1,5,4,3,2},{1,2,7,3,4}};
    // vector<vector<int>> grid = {{5,1,3,1},{9,3,3,1},{1,3,3,8}};
    Solution S;
    cout << S.largestMagicSquare(grid) << endl;
    return 0;
}