#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) height[0][j] = mat[0][j];
        for (int i = 1; i < m; i++){
            for (int j = 0; j < n; j++){
                height[i][j] = (mat[i][j] == 0)? 0 : height[i-1][j] + 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++){
            stack<vector<int>> s;
            s.push({-1, 0, -1});
            for (int j = 0; j < n; j++){
                int curr_height = height[i][j];
                while(s.top()[2] >= curr_height) s.pop();
                int k = s.top()[0];
                int acc = s.top()[1];
                int curr_acc = acc + (j - k) * curr_height;
                s.push({j, curr_acc, curr_height});
                ans += curr_acc;
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> mat = {{1,0,1},{1,1,0},{1,1,0}};
    // vector<vector<int>> mat = {{0,1,1,0},{0,1,1,1},{1,1,1,0}};
    // vector<vector<int>> mat = {{1,1,1,1,0},{1,0,0,1,0},{0,0,1,0,1},{0,1,0,0,0}};
    Solution S;
    cout << S.numSubmat(mat) << endl;
    return 0;
}