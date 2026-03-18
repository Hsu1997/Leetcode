#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> acc(n, 0);
        int ans = 0;
        for (int i = 0; i < m; i++){
            int curr = 0;
            for (int j = 0; j < n; j++){
                acc[j] += grid[i][j];
                curr += acc[j];
                if (curr <= k) ans++;
                else break;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{7,6,3},{6,6,1}};
    int k = 18;
    // vector<vector<int>> grid = {{7,2,9},{1,5,0},{2,6,6}};
    // int k = 20;
    Solution S;
    cout << S.countSubmatrices(grid, k) << endl;
    return 0;
}