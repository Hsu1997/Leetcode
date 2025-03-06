#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2);
        int n = grid.size();
        vector<int> visited(n * n + 1, 0);
        for (auto& row : grid){
            for (int val : row){
                visited[val]++;
                if (visited[val] == 2) ans[0] = val;
            }
        }
        for (int i = 1; i <= n * n; i++){
            if (visited[i] == 0) ans[1] = i;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid = {{1,3},{2,2}};
    // vector<vector<int>> grid = {{9,1,7},{8,9,2},{3,4,6}};
    Solution S;
    vector<int> ans = S.findMissingAndRepeatedValues(grid);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}