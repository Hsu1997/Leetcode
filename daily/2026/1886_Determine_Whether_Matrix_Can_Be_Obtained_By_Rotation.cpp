#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> rotation(vector<vector<int>>& mat){
        int n = mat.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                ans[j][n-1-i] = mat[i][j];
            }
        }
        return ans;
    }
    bool equal(vector<vector<int>>& m1, vector<vector<int>>& m2){
        int n = m1.size();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (m1[i][j] != m2[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> r1 = rotation(mat);
        vector<vector<int>> r2 = rotation(r1);
        vector<vector<int>> r3 = rotation(r2);
        if (equal(mat, target) || equal(r1, target) || equal(r2, target) || equal(r3, target)) return true;
        return false;
    }
};

int main(){
    vector<vector<int>> mat = {{0,1},{1,0}};
    vector<vector<int>> target = {{1,0},{0,1}};
    // vector<vector<int>> mat = {{0,1},{1,1}};
    // vector<vector<int>> target = {{1,0},{0,1}};
    // vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    // vector<vector<int>> target = {{1,1,1},{0,1,0},{0,0,0}};
    Solution S;
    cout << S.findRotation(mat, target) << endl;
    return 0;
}