#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, {1});
        // ans[0][0] = 1;
        for (int level = 1; level < numRows; level++){
            vector<int> temp(level+1, 0);
            // ans[level][0] = 1;
            for (int i = 1; i < level; i++){
                ans[level].push_back(ans[level-1][i-1] + ans[level-1][i]);
            }
            ans[level].push_back(1);
        }
        return ans;
    }
};

int main(){
    int numRows = 10;
    Solution S;
    vector<vector<int>> ans = S.generate(numRows);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
}