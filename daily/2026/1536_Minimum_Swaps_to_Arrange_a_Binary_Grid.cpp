#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = n-1; j >= 0; j--){
                if (grid[i][j] == 0) cnt++;
                else break;
            }
            v[i] = cnt;
        }
        for (int i = 0; i < n; i++){
            if (v[i] >= n - 1 - i) continue;
            int target = i + 1;
            while(target < n && v[target] < n - 1 - i) target++;
            if (target == n) return -1;
            for (int p = target; p > i; p--){
                swap(v[p], v[p-1]);
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,1},{1,1,0},{1,0,0}};
    // vector<vector<int>> grid = {{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};
    // vector<vector<int>> grid = {{1,0,0},{1,1,0},{1,1,1}};
    Solution S;
    cout << S.minSwaps(grid) << endl;
    return 0;
}
