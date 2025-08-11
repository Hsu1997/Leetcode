#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        ans[0] = {1};
        for (int i = 1; i < numRows; i++){
            ans[i].resize(i+1, 1);
            ans[i][0] = 1;
            for (int j = 1; j < i; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};

int main(){
    int numRows = 5;
    // int numRows = 1;
    // int numRows = 10;
    Solution S;
    vector<vector<int>> ans = S.generate(numRows);
    for (auto& row : ans){
        for (auto i : row) cout << i << " ";
        cout << endl;
    }
    return 0;
}